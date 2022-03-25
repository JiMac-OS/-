#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int arr[100][100];
    int N, v = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = v;
                v++;
            }
        }
        else
        {
            for (int j = N - 1; j >= 0; j--)
            {
                arr[i][j] = v;
                v++;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d", arr[i][j]);
        printf("\n");
    }
}