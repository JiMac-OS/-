#include <stdio.h>
void HanoiTowerMove(int num, char from, char by, char to)
{
    if (num == 1)
    {
        printf("원반1을 %c에서 %c로 이동\n", from, to);
    }
    else
    {
        HanoiTowerMove(num - 1, from, to, by);
        printf("원반%d를 %c에서 %c로 이동\n", num, from, to);
        HanoiTowerMove(num - 1, by, from, to);
    }
}

int main(int arc, char **argv)
{
    printf("하노이 타워 재귀 구현\n");
    HanoiTowerMove(3, 'A', 'B', 'C');
    printf("\n");
    printf("하노이 타워 반복문 구현\n");
    Hanoi(3, 'A', 'B', 'C');
    return 0;
}