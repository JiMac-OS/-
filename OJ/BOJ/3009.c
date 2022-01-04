#include <stdio.h>
int main(void)
{
    int X, Y;
    int ax, bx, cx;
    int ay, by, cy;

    scanf("%d %d", &ax, &ay);
    scanf("%d %d", &bx, &by);
    scanf("%d %d", &cx, &cy);

    if (ax == bx)
        X = cx;
    else if (ax == cx)
        X = bx;
    else
        X = ax;

    if (ay == by)
        Y = cy;
    else if (ay == cy)
        Y = by;
    else
        Y = ay;

    printf("%d %d\n", X, Y);
    return 0;
}