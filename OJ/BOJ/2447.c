// BOJ_2447 별 찍기 - 10
#include <stdio.h>
void star(int i, int j, int N);
int main(void)
{
    int n, i, j;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            star(i, j, n);
        }
        printf("\n");
    }
}
void star(int i, int j, int N)
{
    if ((i / N) % 3 == 1 && (j / N) % 3 == 1)
    {
        printf(" ");
    }
    else
    {
        if (N / 3 == 0)
            printf("*");
        else
        {
            star(i, j, N / 3);
        }
    }
}
