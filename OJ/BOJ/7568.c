#include <stdio.h>
int main(void)
{
    int x[50];
    int y[50];
    int N, cnt;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d %d", &x[i], &y[i]);

    for (int i = 0; i < N; i++)
    {
        cnt = 1;
        for (int j = 0; j < N; j++)
        {
            if (x[i] < x[j] && y[i] < y[j])
            {
                cnt++;
            }
        }
        printf("%d ", cnt);
    }
}