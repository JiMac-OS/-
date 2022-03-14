//비트행렬에서 최대 1행 찾기
#include <stdio.h>
#include <stdlib.h>
int mostOnes(int **A, int n);
int main(void)
{
    int N;
    int **arr;
    scanf("%d", &N);
    arr = (int **)malloc(sizeof(int *) * N);
    for (int i = 0; i < N; i++)
        arr[i] = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    }

    printf("%d\n", mostOnes(arr, N));

    for (int i = 0; i < N; i++)
        free(arr[i]);

    free(arr);

    return 0;
}
/* int mostOnes(int **A, int n) // 시간복잡도 O(n^2)
{
    int i, j, max = 0, cnt;
    for (i = 0; i < n; i++)
    {
        cnt = 0;
        for (j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                cnt++;
                if (A[i][j] == 0)
                    break;
            }
        }
        if (cnt > max)
            max = cnt;
    }
    return max;
} */
int mostOnes(int **A, int n)
{
    int i, j, row, jmax;
    i = j = row = 0;
    while ((i < n) && (j < n))
    {
        if (A[i][j] == 0)
            i += 1;
        else
        {
            row = i;
            j += 1;
        }
    }
    return row;
}
/* 8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0 */