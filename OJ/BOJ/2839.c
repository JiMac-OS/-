#include <stdio.h>
int main(void)
{
    int N, cnt = 0;
    scanf("%d", &N);
    while (1)
    {
        if (N % 5 == 0)
        {

            printf("%d\n", N / 5 + cnt);
            break;
        }
        if (N <= 0)
        {
            printf("-1\n");
            break;
        }

        N -= 3;
        cnt++;
    }

    return 0;
}