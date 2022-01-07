// BOJ_2447 별 찍기 - 10
#include <stdio.h>
#include <math.h>
void star(int i, int j, int N);
int main(void)
{
    int N, i, j;
    int map[2188][2188];
    scanf("%d", &N);
    for (i = 0; i < 2188; i++)
    {
        for (j = 0; j < 2188; j++)
        {
            map[i][j] = ' ';
        }
    }

    star(0,0,N);

    return 0;
}
void star(int i, int j, int N)
{
}