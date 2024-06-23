#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int equal_outputs(char *output, const char *expected_output)
{
    if (strcmp(expected_output, output) != 0)
    {
        fprintf(stderr, "unexpected diff in test output.\n");
        fprintf(stderr, "--------expected:--------\n");
        fprintf(stderr, "%s", expected_output);
        fprintf(stderr, "--------got:--------\n");
        fprintf(stderr, "%s\n", output);
        return 1;
    }
    return 0;
}

int jury(const char *binary, const char *inputs[], const char *expected_outputs[], const int testset_len, int (*eval)(char *output, const char *expected_output))
{
    // TODO: input validation, do a different behavior if we don't have expected_outputs and rely on eval function

    int stdoutfds[2], stdinfds[2], i, exitcode, passed = 1;
    char buffer[1024] = {0}, cwd[1024], *program_full_path;
    pid_t pid;
    ssize_t bytes_r, bytes_w;

    if (getcwd(cwd, 1024) == NULL)
    {
        perror("getcwd");
        return 1;
    }

    // cwd now holds the current working directory path
    program_full_path = strcat(cwd, "/");
    program_full_path = strcat(program_full_path, binary);

    for (i = 0; i < testset_len; i++)
    {
        printf("test %d running...\n", i + 1);
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

            if (execl(program_full_path, binary, NULL) < 0)
            {
                fprintf(stderr, "execl(%s, %s, NULL)", program_full_path, binary);
                return 1;
            }
        }

        // jury only writes in stdin and reads stdout
        close(stdinfds[0]);
        close(stdoutfds[1]);

        bytes_w = write(stdinfds[1], inputs[i], strlen(inputs[i]));
        if (bytes_w < 0)
        {
            perror("write on child");
            return kill(pid, SIGTERM);
        }

        // FIXME: read until end of output even if we don't have expected_outputs
        bytes_r = read(stdoutfds[0], buffer, strlen(expected_outputs[i]));
        if (bytes_r < 0)
        {
            perror("read on child");
            return kill(pid, SIGTERM);
        }

        if (eval(buffer, expected_outputs[i]))
        {
            return kill(pid, SIGTERM);
        }

        if (waitpid(pid, &exitcode, 0) != pid)
        {
            perror("wait on child");
            return 1;
        }
        if (exitcode != 0)
        {
            fprintf(stderr, "program exit code: %d\n", exitcode);
            return exitcode;
        }

        if (passed)
        {
            printf("test %d passed!\n", i + 1);
        }

        close(stdinfds[1]);
        close(stdoutfds[0]);
    }

    return 0;
}