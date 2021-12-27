#include <stdio.h>
int PN(int n);
int main(void)
{
    int N, i, j;
    scanf("%d", &N);
    while (N > 1)
    {
        for (i = 2; i <= N; i++)
        {
            if (N % i == 0)
            {
                printf("%d\n", i);
                N /= i;
                break;
            }
        }
    }

    return 0;
}
