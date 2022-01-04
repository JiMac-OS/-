#include <stdio.h>
int main(void)
{
    int x, y, w, h;
    
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int ygap = h - y < y ? h - y : y;
    int xgap = w - x < x ? w - x : x;

    printf("%d\n",ygap<xgap?ygap:xgap);

    return 0;
}