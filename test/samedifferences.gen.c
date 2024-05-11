#include <stdio.h>

int main(int argc, char *argv[])
{
    const size_t maxlen = 100;
    const int static_testsetlen = 2;

    const char *static_inputs[] = {
        "4\n6\n3 5 1 4 6 6\n3\n1 2 3\n4\n1 3 3 4\n6\n1 6 3 4 5 6\n",
        "1\n1\n1\n",
    };

    const char *static_outputs[] = {
        "1\n3\n3\n10\n",
        "0\n",
    };

    char infn[maxlen], outfn[maxlen];
    char inputstr[] = ".inp.", outputstr[] = ".out.";
    if (argc < 2)
    {
        printf("unexpected lack of output file for %s test data generation\n", argv[0]);
        return 1;
    }

    int testidx;
    for (testidx = 0; testidx < static_testsetlen; testidx++)
    {
        sprintf(infn, "%s%s%d", argv[1], inputstr, testidx);
        sprintf(outfn, "%s%s%d", argv[1], outputstr, testidx);

        FILE *fpin = fopen(infn, "w");
        if (fpin == NULL)
        {
            printf("error opening file %s\n", infn);
            return 1;
        }

        fputs(static_inputs[testidx], fpin);
        fclose(fpin);

        FILE *fpout = fopen(outfn, "w");
        if (fpout == NULL)
        {
            printf("error opening file %s\n", outfn);
            return 1;
        }

        fputs(static_outputs[testidx], fpout);
        fclose(fpout);
    }

    // corner case: t == 1, n == 2 * 10 ** 5, a_i = i

    sprintf(infn, "%s%s%d", argv[1], inputstr, testidx);
    sprintf(outfn, "%s%s%d", argv[1], outputstr, testidx);

    FILE *fpin = fopen(infn, "w");
    if (fpin == NULL)
    {
        printf("error opening file %s\n", infn);
        return 1;
    }

    FILE *fpout = fopen(outfn, "w");
    if (fpout == NULL)
    {
        printf("error opening file %s\n", outfn);
        return 1;
    }
    fputs("1\n200000\n", fpin);
    for (int a_i = 1; a_i <= 200000; a_i++)
    {
        if (a_i > 1)
        {
            fputs(" ", fpin);
        }

        fprintf(fpin, "%d", a_i);
    }
    fputs("19999900000\n", fpout);
    fclose(fpin);
    fclose(fpout);

    return 0;
}