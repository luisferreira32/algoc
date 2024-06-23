#include <stdio.h>
#include <stdlib.h>

#define MAX_K 1000000000

int main()
{
    unsigned long long n, i, k, count = 0, divisor = -1, k_b = 0, k_e = MAX_K - 1, *k_cache, k_pair;

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

            k_pair = n / i;
            if (k_pair != i)
            {
                k_cache[k_e] = k_pair;
                k_e--;
            }

            if (count == k)
            {
                break;
            }
        }
    }

    if (count * 2 < k)
    {
        printf("-1\n");
        free(k_cache);
        return 0;
    }

    count = 0;
    for (i = 0; i < MAX_K; i++)
    {
        // skip the blank zeroes and go for the pairs
        if (i == k_b)
        {
            i = k_e + 1;
        }

        count++;
        if (count == k)
        {
            divisor = k_cache[i];
            break;
        }
    }

    free(k_cache);
    printf("%lld\n", divisor);

    return 0;
}