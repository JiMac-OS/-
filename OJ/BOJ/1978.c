#include <stdio.h>
int Prime_Number(int n);
int main(void)
{
    int N, M, min = 100001, sum = 0, cnt = 0;
    int i, j;
    scanf("%d %d", &N, &M);

    for (i = N; i <= M; i++)
    {
        int pn = Prime_Number(i);
        if (pn == 1)
        {
            sum += i;
            cnt++;
            if (min > i)
                min = i;
        }
    }
    if (cnt > 0)
        printf("%d\n%d\n", sum, min);
    else
        printf("-1\n");

    return 0;
}
int Prime_Number(int n)
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