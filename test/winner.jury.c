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
        "3\nmike 3\nandrew 5\nmike 2\n",
        "3\nandrew 3\nandrew 2\nmike 5\n",
        "7\nksjuuerbnlklcfdjeyq 312\ndthjlkrvvbyahttifpdewvyslsh -983\nksjuuerbnlklcfdjeyq 268\ndthjlkrvvbyahttifpdewvyslsh 788\nksjuuerbnlklcfdjeyq -79\nksjuuerbnlklcfdjeyq -593\nksjuuerbnlklcfdjeyq 734\n",
    };

    const char *static_outputs[] = {
        "andrew\n",
        "andrew\n",
        "ksjuuerbnlklcfdjeyq\n",
    };

    if (argc < 2)
    {
        fprintf(stderr, "unexpected lack of binary to judge by %s\n", argv[0]);
        return 1;
    }

    return jury(argv[1], static_inputs, static_outputs, static_testsetlen, equal_outputs);
}