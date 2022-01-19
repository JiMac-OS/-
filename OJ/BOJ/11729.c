#include <stdio.h>
#include <math.h>
void move(int n, int start, int end);
void hanoi(int n, int start, int end);
void hanoi_sub(int n, int start, int end, int other);
int main(void)
{
    int N;
    scanf("%d", &N);
    printf("%.0f\n", pow(2, N) - 1);
    hanoi(N, 1, 3);

    return 0;
}
void move(int n, int start, int end)
{
    printf("%d %d\n", start, end);
}
void hanoi_sub(int n, int start, int end, int other)
{
    if (n == 1)
        move(1, start, end);
    else
    {
        hanoi_sub(n - 1, start, other, end);
        move(n, start, end);
        hanoi_sub(n - 1, other, end, start);
    }
}
void hanoi(int n, int start, int end)
{
    hanoi_sub(n, start, end, 2);
}
// https://www.youtube.com/watch?v=uSSC0aKXbWQ
// 그냥 입력하는 것이다. 이 유튜버 정독하자.
// 그냥 문장을 코드로 입력만 하는 것이 바로 재귀이다.