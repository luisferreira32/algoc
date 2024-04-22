#include <stdio.h>

int main()
{
    int n, m, a, b, extra = 0;

    scanf("%d %d %d %d", &n, &m, &a, &b);

    if (b < a * m)
    {
        if ((n % m) * a < b)
        {
            extra = (n % m) * a;
        }
        else
        {
            extra = b;
        }

        printf("%d\n", extra + (n / m) * b);
    }
    else
    {
        printf("%d\n", a * n);
    }

    return 0;
}