#include <stdio.h>
int main(void)
{
    int N, M, i, j;
    int arr[1000001] = {
        0,
    };
    arr[1] = 1; // 1은 소수가 아니므로 1을 입력

    // 소수면 0, 소수가 아니면 1

    scanf("%d %d", &M, &N);

    for (i = 2; i <= N; i++)
    {
        if (arr[i] == 0)
        {
            for (j = 2; i * j <= N; j++)
            {
                arr[i * j] = 1;
            }
        }
    }

    for (i = M; i <= N; i++)
        if (arr[i] == 0)
            printf("%d\n", i);

    return 0;
}
