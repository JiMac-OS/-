#include <stdio.h>
typedef struct a
{
    int h, m, s;
} time;
int main(void)
{
    time t1, t2;
    int gh, gm, gs;
    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

    gs = t2.s - t1.s;
    gm = t2.m - t1.m;
    gh = t2.h - t1.h;

    if (gs < 0)
    {
        gm--;
        gs += 60;
    }
    if (gm < 0)
    {
        gh--;
        gm += 60;
    }
    printf("%d %d %d\n", gh, gm, gs);

    return 0;
}