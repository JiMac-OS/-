#include <stdio.h>
#define PI 3.14159265359
int main(void)
{
    int R;
    scanf("%d", &R);
    printf("%.6lf\n%.6lf\n", (double)R * R * PI, (double)R * R * 2);
    return 0;
}