#include <stdio.h>
#include <stdlib.h>
int mostOnes(int **arr, int n)
{
    int i, j, row, jmax;
    i = j = row = jmax = 0;

    for (i = 0; i < n; i++)
    {
        while (((j < n) && (i < n)))
        {
            if (arr[i][j] == 0)
                i++;
            else
            {
                j++;
                row = i;
            }
            if (jmax < row)
                jmax = row;
        }
    }
    return jmax;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int **arr;
    arr = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n", mostOnes(arr, n));

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}