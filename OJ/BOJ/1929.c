#include <stdio.h>
int PN(int n);
int main(void)
{
    int N, M;
    int i;

    scanf("%d %d", &N, &M);
    for (i = N; i <= M; i++)
        if (PN(i) == 1)
            printf("%d\n", i);

    return 0;
}
int PN(int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
            break;
    }
    if (n == i)
        return 1;
    else
        return 0;
}
