#include <stdio.h>

int main()
{
    int i, num;

    scanf("%d\n", &num);

    int x = 0;
    char buff[5];
    for (i = 0; i < num; i++)
    {
        fgets(buff, 5, stdin);
        if (buff[1] == '-')
        {
            x--;
        }
        else
        {
            x++;
        }
    }
    printf("%d\n", x);

    return 0;
}