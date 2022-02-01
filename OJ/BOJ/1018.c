//변을 공유하는 2개의 사각형은 다른 색깔로 칠해야 한다.
#include <stdio.h>
int main(void)
{
    int N, M;
    char board[50][50];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    return 0;
}