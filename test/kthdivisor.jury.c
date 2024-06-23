#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "internal/jury.h"

int main(int argc, char *argv[])
{
    const int static_testsetlen = 4;
    const char *static_inputs[] = {
        "4 2\n",
        "5 3\n",
        "12 5\n",
        "1000000000000000 1000000000\n",
    };
    const char *static_outputs[] = {
        "2\n",
        "-1\n",
        "6\n",
        "-1\n",
    };

    if (argc < 2)
    {
        fprintf(stderr, "unexpected lack of binary to judge by %s\n", argv[0]);
        return 1;
    }

    return jury(argv[1], static_inputs, static_outputs, static_testsetlen, equal_outputs);
}