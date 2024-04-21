#include <stdio.h>

int main()
{
    char buffer[101], previous_player;
    int i, dangerous = 0;

    fgets(buffer, 100, stdin);

    previous_player = buffer[0];
    for (i = 0; i < 100; i++)
    {
        if (buffer[i] == '\n')
        {
            break;
        }
        if (buffer[i] == previous_player)
        {
            dangerous++;
        }
        else
        {
            dangerous = 1;
        }
        if (dangerous > 6)
        {
            printf("YES\n");
            return 0;
        }

        previous_player = buffer[i];
    }

    printf("NO\n");

    return 0;
}
