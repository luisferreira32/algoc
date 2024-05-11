#include <stdio.h>

int main(int argc, char *argv[])
{
    const size_t maxlen = 100;
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

    char infn[maxlen], outfn[maxlen];
    char inputstr[] = ".inp.", outputstr[] = ".out.";
    if (argc < 2)
    {
        printf("unexpected lack of output file for %s test data generation\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < static_testsetlen; i++)
    {
        sprintf(infn, "%s%s%d", argv[1], inputstr, i);
        sprintf(outfn, "%s%s%d", argv[1], outputstr, i);

        FILE *fpin = fopen(infn, "w");
        if (fpin == NULL)
        {
            printf("error opening file %s\n", infn);
            return 1;
        }

        fputs(static_inputs[i], fpin);
        fclose(fpin);

        FILE *fpout = fopen(outfn, "w");
        if (fpout == NULL)
        {
            printf("error opening file %s\n", outfn);
            return 1;
        }

        fputs(static_outputs[i], fpout);
        fclose(fpout);
    }

    return 0;
}