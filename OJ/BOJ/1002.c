#include <stdio.h>
#include <math.h>
int main(void)
{
    int t;
    int x1, x2, y1, y2, r1, r2;
    double d, sub;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        sub = r1 > r2 ? r1 - r2 : r2 - r1;

        if (d == 0 && r1 == r2)
            printf("-1\n");
        else if (sub < d && r1 + r2 > d)
            printf("2\n");
        else if (sub == d || r1 + r2 == d)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}