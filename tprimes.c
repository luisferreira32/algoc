#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIME 1000000 // sqrt (10^12) = 10^6 ~ 1MiB

int main()
{
    int i, j, num, min_guess, max_guess, guess, is_tprime, num_of_primes = 0, *prime_sieve;
    long long unsigned int candidate = 0, *prime_cache;

    // need to be on heap otherwise gives a stack overflow
    prime_sieve = (int *)calloc(MAX_PRIME, sizeof(int));
    if (prime_sieve == NULL)
    {
        return 1;
    }

    prime_cache = (long long unsigned int *)calloc(MAX_PRIME, sizeof(long long unsigned int));
    if (prime_sieve == NULL)
    {
        free(prime_sieve);
        return 1;
    }

    scanf("%d", &num);

    for (i = 2; i < MAX_PRIME; i++)
    {
        prime_sieve[i] = 1;
    }

    for (i = 2; i * i < MAX_PRIME; i++)
    {
        if (prime_sieve[i])
        {
            for (j = i * i; j < MAX_PRIME; j += i)
            {
                prime_sieve[j] = 0;
            }
        }
    }
    for (i = 2; i < MAX_PRIME; i++)
    {
        if (prime_sieve[i])
        {
            prime_cache[num_of_primes] = i;
            num_of_primes++;
        }
    }

    for (i = 0; i < num; i++)
    {
        scanf("%lld", &candidate);
        if (candidate < 4)
        {
            printf("NO\n");
            continue;
        }
        is_tprime = 0;
        min_guess = 0;
        max_guess = num_of_primes;
        guess = min_guess + (max_guess - min_guess) / 2;
        if (prime_cache[guess] * prime_cache[guess] == candidate)
        {
            printf("YES\n");
            continue;
        }

        while (guess != min_guess) // round downs
        {
            if (prime_cache[guess] * prime_cache[guess] > candidate)
            {
                max_guess = guess;
            }
            else
            {
                min_guess = guess;
            }
            guess = min_guess + (max_guess - min_guess) / 2;
            if (prime_cache[guess] * prime_cache[guess] == candidate)
            {
                is_tprime = 1;
                break;
            }
        }

        if (is_tprime)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        candidate = 0;
    }

    free(prime_sieve);
    free(prime_cache);
    return 0;
}