#include <stdio.h>
#include <string.h>

#define MAX_N 10000

int main()
{
    int n, m, n_i, steps = 0, i = 0, j = 0;
    int visited[2 * MAX_N + 1] = {0}, queue[2 * MAX_N + 1] = {0};

    // 1 <= n, m <= 10**4
    scanf("%d %d", &n, &m);

    visited[n] = -1; // marker for the start
    queue[i] = n;
    while (j <= i)
    {
        n_i = queue[j];
        j++;

        if (n_i == m)
        {
            break;
        }

        // ignore branches that will only grow too much: we don't want to be stack smashing
        if ((n_i > m * 2 && n < m) || (n_i > n && m < n))
        {
            continue;
        }

        if (n_i < 2 * MAX_N && visited[n_i * 2] == 0)
        {
            visited[n_i * 2] = n_i;
            i++;
            queue[i] = n_i * 2;
        }

        if (n_i > 1 && visited[n_i - 1] == 0)
        {
            visited[n_i - 1] = n_i;
            i++;
            queue[i] = n_i - 1;
        }
    }

    if (n_i != m)
    {
        printf("no valid path\n");
        return 1;
    }

    while (visited[n_i] != -1)
    {
        n_i = visited[n_i];
        steps++;
    }

    printf("%d\n", steps);

    return 0;
}