#include <stdio.h>

int main()
{
    int i, num;
    long long unsigned int max_num = 10000000;

    scanf("%d", &num);

    for (i = 1; i <= num - 1; i++)
    {
        printf("%lld ", max_num - num + i);
    }
    printf("%lld\n", max_num);

    return 0;
}