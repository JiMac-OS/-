#include <stdio.h>
int main(void)
{
    int N, M;
    int check = 0;

    scanf("%d", &N);

    for (int i = 1; i < N; i++)
    {
        int tmp = i;
        int n = i;
        while (n)
        {
            tmp += n % 10;
            n /= 10;
        }

        if (tmp == N)
        {
            printf("%d\n", i);
            check = 1;
            break;
        }
    }
    if (check == 0)
        printf("0\n");
    return 0;
}