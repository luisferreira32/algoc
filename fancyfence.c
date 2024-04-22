#include <stdio.h>

int main()
{
    int i, num, angle;

    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%d", &angle);
        // (n-2)*180 = n*a => n = 2/(1-a/180)
        if ((360 % (180 - angle)) == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}