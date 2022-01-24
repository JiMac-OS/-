#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N, *ar1, *ar2;
    int *p, *q;
    scanf("%d", &N);
    ar1 = (int *)malloc(sizeof(int) * N);
    ar2 = (int *)malloc(sizeof(int) * N);

    for (p = ar1; p < ar1 + N; p++)
        scanf("%d", p);

    for (p = ar2; p < ar2 + N; p++)
        scanf("%d", p);

    for (p = ar1, q = ar2 + N - 1; p < ar1 + N; p++, q--)
        printf(" %d", *p + *q);

    free(ar1);
    free(ar2);

    return 0;
}