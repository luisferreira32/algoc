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
    const int static_testsetlen = 11;

    const char *static_inputs[] = {
        "4 6\n",
        "10 1\n",
        "1 2\n",
        "2 1\n",
        "1 3\n",
        "3 1\n",
        "2 10\n",
        "100 99\n",
        "99 100\n",
        "666 6666\n",
        "6666 666\n",
    };

    const char *static_outputs[] = {
        "2\n",
        "9\n",
        "1\n",
        "1\n",
        "3\n",
        "2\n",
        "5\n",
        "1\n",
        "50\n",
        "255\n",
        "6000\n",
    };

    if (argc < 2)
    {
        fprintf(stderr, "unexpected lack of binary to judge by %s\n", argv[0]);
        return 1;
    }

    return jury(argv[1], static_inputs, static_outputs, static_testsetlen, equal_outputs);
}