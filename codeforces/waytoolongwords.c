#include <stdio.h>
#include <string.h>

int main()
{
    int i, num, len;
    char buffer[102]; // 1 to 100 characters + \n + \0

    scanf("%d\n", &num);

    for (i = 0; i < num; i++)
    {
        fgets(buffer, 102, stdin);
        len = strlen(buffer);

        if (len - 1 > 10) // account for \n
        {
            printf("%c%d%c\n", buffer[0], len - 3, buffer[len - 2]);
        }
        else
        {
            printf("%s", buffer);
        }
    }

    return 0;
}