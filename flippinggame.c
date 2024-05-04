#include <stdio.h>

int main()
{
    // 1 <= num <= 100 -- easily bruteforced
    int n, num, arr[100], c_ones[100] = {0}, c_zeros[100] = {0};

    scanf("%d", &num);

    for (n = 0; n < num; n++)
    {
        scanf("%d", &arr[n]);
    }

    c_ones[0] = arr[0];
    c_zeros[0] = 1 - arr[0];
    for (n = 1; n < num; n++)
    {
        c_ones[n] = c_ones[n - 1] + arr[n];
        c_zeros[n] = c_zeros[n - 1] + 1 - arr[n];
    }

    int i, j, max_flip = 0;

    // corner case i = 0, count every part of the cumulative arrays
    for (j = 0; j < num; j++)
    {
        if (max_flip < c_zeros[j] - c_ones[j])
        {
            max_flip = c_zeros[j] - c_ones[j];
        }
    }

    for (i = 1; i < num; i++)
    {
        for (j = i; j < num; j++)
        {
            if (max_flip < (c_zeros[j] - c_zeros[i - 1]) - (c_ones[j] - c_ones[i - 1]))
            {
                max_flip = (c_zeros[j] - c_zeros[i - 1]) - (c_ones[j] - c_ones[i - 1]);
            }
        }
    }

    // corner case, every element is a 1 and we must flip at least once
    if (c_ones[num - 1] == num)
    {
        max_flip -= 1;
    }

    printf("%d\n", c_ones[num - 1] + max_flip);

    return 0;
}