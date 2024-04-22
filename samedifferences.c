#include <stdio.h>
#include <string.h>

const int maxlen = 200001;

int main()
{
    // 1 <= n <= maxlen - 1
    // 1 <= a_i <= n => 0 <= a_i - i <= n
    int t, n, arr[maxlen], c_neg_arr[maxlen], c_pos_arr[maxlen], i;
    long long unsigned int numpair;

    scanf("%d", &t);

    while (t--)
    {
        memset(c_pos_arr, 0, sizeof(int) * maxlen);
        memset(c_neg_arr, 0, sizeof(int) * maxlen);

        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        numpair = 0;

        for (i = 0; i < n; i++)
        {
            if (arr[i] - i > 0)
            {
                numpair += c_pos_arr[arr[i] - i];
                c_pos_arr[arr[i] - i]++;
            }
            else
            {
                numpair += c_neg_arr[i - arr[i]];
                c_neg_arr[i - arr[i]]++;
            }
        }

        printf("%lld\n", numpair);
    }

    return 0;
}
