#include <stdio.h>

int main()
{
    const char hello[5] = "hello";

    char buffer[102];
    int i, hello_ptr = 0;

    fgets(buffer, 101, stdin);

    for (i = 0; i < 102; i++)
    {
        if (buffer[i] == '\n' || hello_ptr == 5)
        {
            break;
        }
        if (hello[hello_ptr] == buffer[i])
        {
            hello_ptr++;
        }
    }
    if (hello_ptr == 5)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}