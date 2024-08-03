#include <stdio.h>
#include <stdlib.h>

#define MAX_K 10000000

int main()
{
    unsigned long long n, i, k, count = 0, k_b = 0, k_e = MAX_K - 1, *k_cache;

    k_cache = (unsigned long long *)calloc(MAX_K, sizeof(unsigned long long));

    // 1 ≤ n ≤ 10**15, 1 ≤ k ≤ 10**9
    scanf("%lld %lld", &n, &k);

    for (i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            k_cache[k_b] = i;
            k_b++;

            if (i * i != n)
            {
                count++;
                k_cache[k_e] = n / i;
                k_e--;
            }
        }
    }

    if (count < k)
    {
        printf("-1\n");
        free(k_cache);
        return 0;
    }

    count = 0;
    if (k - 1 < k_b)
    {
        printf("%lld\n", k_cache[k - 1]);
        i = k_e + 1;
    }
    else
    {
        i = k - k_b + k_e; // kth, meaning 1st = 0
        printf("%lld\n", k_cache[i]);
    }

    free(k_cache);

    return 0;
}