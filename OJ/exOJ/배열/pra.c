#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int N = 0, M = 0;
    int arr[100][100];
    int i, j;
    int a, b;
    int num = 1;
    a = b = 0;
    scanf("%d %d", &N, &M);

    for (i = 0; i < M; i++)
    {
        a = 0;
        b = i;
        while (a < N && b >= 0)
        {
            arr[a++][b--] = num++;
        }
    }
    for (j = 1; j < N; j++)
    {
        a = j;
        b = M - 1;
        while (a < N && b >= 0)
        {
            arr[a++][b--] = num++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf("%3d", arr[i][j]);
        printf("\n");
    }
    return 0;
}