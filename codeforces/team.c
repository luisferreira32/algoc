#include <stdio.h>

int main()
{
    int i, num;
    int sol[3], numsol = 0;

    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d %d %d", &sol[0], &sol[1], &sol[2]);
        if (sol[0] + sol[1] + sol[2] > 1)
        {
            numsol++;
        }
    }
    printf("%d\n", numsol);

    return 0;
}