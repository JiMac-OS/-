#include <stdio.h>
#include <string.h>
int main(void)
{
    int A, B, V;
    int day, least, HM, ans;
    scanf("%d %d %d", &A, &B, &V);

    if (A == V)
    {
        printf("1\n");
        return 0;
    }

    day = A - B;
    least = V - A; // 여기까지 오면 다음날 정상도착
    if (least % day == 0)
    {
        HM = least / day;
    }
    else
    {
        HM = least / day + 1; //나눠 떨어지지 않으면 하루 더 가야 한다.
    }
    ans = HM + 1;

    printf("%d\n", ans);

    return 0;
}