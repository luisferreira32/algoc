#include <stdio.h>

int main()
{
    int i, num, a_arr[100001], count_arr[4];

    scanf("%d\n", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &a_arr[i]);
    }

    for (i = 0; i < 4; i++)
    {
        count_arr[i] = 0;
    }

    for (i = 0; i < num; i++)
    {
        // s_i is between 1 and 4;
        count_arr[a_arr[i] - 1]++;
    }

    int taxinum = 0, remain = 0;

    // groups of 4 occupy one taxi
    taxinum += count_arr[3];
    // groups of 3 occupy one taxi and can add a group of 1 with them
    taxinum += count_arr[2];
    if (count_arr[0] > count_arr[2])
    {
        remain = count_arr[0] - count_arr[2];
    }
    // groups of 2 occupy half a taxi
    taxinum += count_arr[1] / 2;
    if (count_arr[1] % 2)
    {
        taxinum++;
        remain -= 2;
    }
    if (remain > 0)
    {
        taxinum += remain / 4;
        if (remain % 4)
        {
            taxinum++;
        }
    }

    printf("%d\n", taxinum);

    return 0;
}