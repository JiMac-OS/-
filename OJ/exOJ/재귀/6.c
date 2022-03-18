#include <stdio.h>
int gcd(int a, int b);
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}