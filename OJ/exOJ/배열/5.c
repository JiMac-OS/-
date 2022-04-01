#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[100][100] = {
        0,
    };
    int row, col, k, val = 0;
    scanf("%d %d", &col, &row);
    for (int j = 0; j < row; j++)
    {
        k = 0;
        for (int i = j; i >= 0 && k != col; i--)
        {
            val++;
            a[k++][i] = val;
        }
    }

    for (int j = 1; j < col; j++)
    {
        k = row - 1;
        for (int i = j; i < col && k >= 0; i++)
        {
            val++;
            a[i][k--] = val;
        }
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}