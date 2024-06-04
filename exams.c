#include <stdio.h>
#include <stdlib.h>

#define MAX_N 5000

struct exam
{
    //  (1 ≤ bi < ai ≤ 10^9)
    unsigned long long int a;
    unsigned long long int b;
};

int compare_exams(const void *p, const void *q)
{
    struct exam x = *(const struct exam *)p;
    struct exam y = *(const struct exam *)q;
    if (x.a != y.a)
    {
        return (x.a > y.a) - (x.a < y.a);
    }
    return (x.b > y.b) - (x.b < y.b);
}

int main()
{
    int i, num;
    unsigned long long int last_exam_day = 0;
    struct exam e[MAX_N] = {0};

    // (1 ≤ n ≤ 5000)
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%lld %lld", &e[i].a, &e[i].b);
    }

    // desired order of professors writing the exam marks
    qsort(e, num, sizeof(*e), compare_exams);

    last_exam_day = e[0].b;
    for (i = 0; i < num; i++)
    {
        if (last_exam_day > e[i].b)
        {
            last_exam_day = e[i].a; // bi < ai, and ai are already sorted
        }
        else
        {
            last_exam_day = e[i].b;
        }
    }

    printf("%lld\n", last_exam_day);

    return 0;
}