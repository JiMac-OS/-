#include <stdio.h>
int Prime_Number(int n);
int main(void)
{
    int N, cnt = 0;
    scanf("%d", &N);
    cnt = Prime_Number(N);
    printf("%d\n", cnt);

    return 0;
}
int Prime_Number(int n)
{
    int i, j, cnt = 0, pn;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pn);
        for (j = 2; j < pn; j++)
        {
            if (pn % j == 0)
                break;
        }
        if (pn == j)
            cnt++;
    }

    return cnt;
}