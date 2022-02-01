#include <stdio.h>
#include <stdlib.h>
int modulo(int a, int b);
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", modulo(a, b));
    return 0;
}
int modulo(int a, int b)
{
    /* if (a < b)
        return a;
    return modulo(a - b, b); */
    //재귀 함수

    while (a > b)
    {
        a -= b;
    }
    return a;
}

// 반복되는 것을 찾고
// 마지막 계산에서 종료되는 순간의 규칙을(일반항) 찾는다.