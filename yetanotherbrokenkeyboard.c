#include <stdio.h>

int main()
{
    int i, j, num, k;
    long long unsigned int res = 0;
    char problem_string[200002], available_char[26];

    // 1 <= n <= 2*10^5, 1 <= k <= 26
    scanf("%d %d\n", &num, &k);
    fgets(problem_string, 200002, stdin);
    for (i = 0; i < k - 1; i++)
    {
        scanf("%c ", &available_char[i]);
    }
    scanf("%c", &available_char[i]);

    int cumulative_comb[200002] = {0};

    // O(N*K) cpu
    // O(N*K) mem

    // i == 0 cannot acumulate from prev
    for (j = 0; j < k; j++)
    {
        if (problem_string[0] != available_char[j])
        {
            continue;
        }
        cumulative_comb[0]++;
        break;
    }

    for (i = 1; i < num; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (problem_string[i] != available_char[j])
            {
                continue;
            }
            cumulative_comb[i] += cumulative_comb[i - 1] + 1;
            break;
        }
    }
    for (i = 0; i < num; i++)
    {
        res += cumulative_comb[i];
    }

    printf("%lld\n", res);

    return 0;
}