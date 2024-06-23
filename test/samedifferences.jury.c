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
    const int static_testsetlen = 2;
    const char *static_inputs[] = {
        "4\n6\n3 5 1 4 6 6\n3\n1 2 3\n4\n1 3 3 4\n6\n1 6 3 4 5 6\n",
        "1\n1\n1\n",
    };
    const char *static_outputs[] = {
        "1\n3\n3\n10\n",
        "0\n",
    };

    if (argc < 2)
    {
        fprintf(stderr, "unexpected lack of binary to judge by %s\n", argv[0]);
        return 1;
    }

    return jury(argv[1], static_inputs, static_outputs, static_testsetlen, equal_outputs);
}