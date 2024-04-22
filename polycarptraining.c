#include <stdio.h>

int main()
{
    int i, num, a_arr[200001], count_arr[200001];

    scanf("%d\n", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &a_arr[i]);
    }

    for (i = 0; i < 200001; i++)
    {
        count_arr[i] = 0;
    }

    // the fact that a_i and n are within the same range points to count "sort".
    for (i = 0; i < num; i++)
    {
        count_arr[a_arr[i]]++;
    }

    int maxk = 0;

    for (i = 0; i < 200001; i++)
    {
        while (maxk < i && count_arr[i] > 0)
        {
            count_arr[i]--;
            maxk++;
        }
    }
    printf("%d\n", maxk);

    return 0;
}