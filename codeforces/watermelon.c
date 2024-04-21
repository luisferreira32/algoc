#include <stdio.h>

int main()
{
    int num;

    scanf("%d", &num);

    if (num > 2 && num % 2 == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}