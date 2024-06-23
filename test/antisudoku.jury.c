#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// TODO: use the shared jury once the FIXME of reading output is done

int main(int argc, char *argv[])
{
    const int static_testsetlen = 1;
    const char *static_inputs[] = {
        "1\n154873296\n386592714\n729641835\n863725149\n975314628\n412968357\n631457982\n598236471\n247189563\n",
    };

    int stdoutfds[2], stdinfds[2], i, exitcode;
    char buffer[1024], cwd[1024], *program_full_path;
    pid_t pid;
    ssize_t bytes_r, bytes_w;

    int n, row, col, block, validated, row_check[10], col_check[10], block_check[10];

    if (argc < 2)
    {
        fprintf(stderr, "unexpected lack of binary to judge by %s\n", argv[0]);
        return 1;
    }

    if (getcwd(cwd, 1024) == NULL)
    {
        perror("getcwd");
        return 1;
    }
    // cwd now holds the current working directory path
    program_full_path = strcat(cwd, "/");
    program_full_path = strcat(program_full_path, argv[1]);

    for (i = 0; i < static_testsetlen; i++)
    {
        memset(buffer, 0, 1024); // clean output buffer

        if (pipe(stdoutfds) < 0 || pipe(stdinfds) < 0)
        {
            perror("pipes");
            return 1;
        }

        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            return 1;
        }

        // execute the program that is being judged
        // program only reads stdin and writes stdout
        if (pid == 0)
        {
            close(stdinfds[1]);
            close(stdoutfds[0]);

            dup2(stdoutfds[1], STDOUT_FILENO);
            dup2(stdinfds[0], STDIN_FILENO);

            if (execl(program_full_path, argv[1], NULL) < 0)
            {
                fprintf(stderr, "execl(%s, %s, NULL)", program_full_path, argv[1]);
                return 1;
            }
        }

        // jury only writes in stdin and reads stdout
        close(stdinfds[0]);
        close(stdoutfds[1]);

        bytes_w = write(stdinfds[1], static_inputs[i], strlen(static_inputs[i]));
        if (bytes_w < 0)
        {
            perror("write on child");
            return kill(pid, SIGTERM);
        }

        bytes_r = read(stdoutfds[0], buffer, 1024);
        if (bytes_r < 0)
        {
            perror("read on child");
            return kill(pid, SIGTERM);
        }

        // Verify we actually have a valid anti-sudoku:
        // rows have a non-unique number
        // columns have a non-unique number
        // blocks have a non-unique number
        row = 0;
        for (n = 0; n < bytes_r; n++)
        {
            if (n % 9 == 0)
            {
                memset(row_check, 0, 10 * sizeof(int));
                if (validated == 0)
                {
                    printf("not an anti-sudoku row %d was a perfect sudoku!\n", row);
                    return kill(pid, SIGTERM);
                }
                validated = 0;

                row++;
            }

            // 0 in ASCII is 48
            row_check[buffer[n] - 48]++;
            if (row_check[buffer[n] - 48] > 1)
            {
                validated = 1;
                continue;
            }
        }

        col = 0;
        for (n = col;; n += 9)
        {
            if (n >= bytes_r + 9 - 1) // finished the iterations
            {
                break;
            }

            if (n >= bytes_r && n < bytes_r + 9 - 1) // previous was the last row of the column
            {
                memset(col_check, 0, 10 * sizeof(int));
                if (validated == 0)
                {
                    printf("not an anti-sudoku col %d was a perfect sudoku!\n", col);
                    return kill(pid, SIGTERM);
                }
                validated = 0;

                col++;
                n = col;
            }

            // 0 in ASCII is 48
            col_check[buffer[n] - 48]++;
            if (col_check[buffer[n] - 48] > 1)
            {
                validated = 1;
                continue;
            }
        }

        block = 0;

        // TODO check blocks

        if (waitpid(pid, &exitcode, 0) != pid)
        {
            return exitcode;
        }
        printf("test %d passed!\n", i + 1);

        close(stdinfds[1]);
        close(stdoutfds[0]);
    }

    return 0;
}