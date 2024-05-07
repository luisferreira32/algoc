#include <stdio.h>

#define MAX_PRIME 100000 // sqrt (10^12) = 10^6

int main()
{
    int i, j, num, guess, is_tprime, num_of_primes = 0, prime_sieve[MAX_PRIME] = {0};
    long long unsigned int candidate = 0, prime_cache[MAX_PRIME] = {0};

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
        scanf("%d", &candidate); // TODO: fix reading of ldd -> fgets + strol?
        if (candidate < 4)
        {
            printf("NO\n");
            continue;
        }
        is_tprime = 0;
        guess = num_of_primes / 2;
        while (guess > 0 && guess < num_of_primes)
        {
            if (prime_cache[guess] * prime_cache[guess] == candidate)
            {
                is_tprime = 1;
                break;
            }
            if (prime_cache[guess] * prime_cache[guess] > candidate)
            {
                guess = guess / 2;
            }
            else
            {
                guess = guess + (num_of_primes - guess) / 2;
            }
        }
        if (guess == 0 && prime_cache[guess] * prime_cache[guess] == candidate)
        {
            is_tprime = 1;
        }

        if (is_tprime)
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