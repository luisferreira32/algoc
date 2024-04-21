#include <stdio.h>

int main()
{
    int num;

    scanf("%d", &num);

    int sol[3], numsol = 0;
    for (size_t i = 0; i < num; i++)
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