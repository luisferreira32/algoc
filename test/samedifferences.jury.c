#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    const int static_testsetlen = 2;
    const char *static_inputs[] = {
        "4\n6\n3 5 1 4 6 6\n3\n1 2 3\n4\n1 3 3 4\n6\n1 6 3 4 5 6\n",
        "1\n1\n1\n",
    };
    const char *static_outputs[] = {
        "1\n3\n3\n10\n",
        "0\n",
    };

    int stdoutfds[2], stdinfds[2], i, exitcode;
    char buffer[1024] = {0}, cwd[1024], *program_full_path;
    pid_t pid;
    ssize_t bytes_r, bytes_w;

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

        bytes_r = read(stdoutfds[0], buffer, strlen(static_outputs[i]));
        if (bytes_r < 0)
        {
            perror("read on child");
            return kill(pid, SIGTERM);
        }

        if (strcmp(static_outputs[i], buffer) != 0)
        {
            fprintf(stderr, "unexpected diff in output %d.\n", i);
            fprintf(stderr, "--------expected:--------\n");
            fprintf(stderr, "%s", static_outputs[i]);
            fprintf(stderr, "--------got:--------\n");
            fprintf(stderr, "%s", buffer);
            return kill(pid, SIGTERM);
        }

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