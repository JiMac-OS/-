#include <stdio.h>
/* int PN(int N);
int main(void)
{

    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("%d\n", PN(n));
    }
    return 0;
}
int PN(int N)
{
    int i, j, cnt = 0;
    for (i = N + 1; i <= 2 * N; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
        }
        if (i == j)
            cnt++;
    }
    return cnt;
} */
// 코린이 코드... 시간 존나 오래쓰는 코드
int PN(int n);
int main(void)
{
    int arr[246913] = {
        0,
    };
    arr[1] = 1; // 소수면 0 아니면 1
    int i, cnt = 0, n, j;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        cnt = 0;

        for (i = 2; i <= 2 * n; i++)
        {
            if (arr[i] == 0)
            {
                for (j = 2; i * j <= 2 * n; j++)
                {
                    arr[i * j] = 1;
                }
            }
        }

        for (i = n + 1; i <= 2 * n; i++)
            if (arr[i] == 0)
                cnt++;

        printf("%d\n", cnt);
    }

    return 0;
}
