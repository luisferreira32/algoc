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
    const int static_testsetlen = 3;
    const char *static_inputs[] = {
        "3\n4 5 6\n",
        "3\n9 10 1\n",
        "1\n999966000289\n",
    };
    const char *static_outputs[] = {
        "YES\nNO\nNO\n",
        "YES\nNO\nNO\n",
        "YES\n",
    };

    if (argc < 2)
    {
        fprintf(stderr, "unexpected lack of binary to judge by %s\n", argv[0]);
        return 1;
    }

    return jury(argv[1], static_inputs, static_outputs, static_testsetlen, equal_outputs);
}