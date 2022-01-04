#include <stdio.h>
int main(void)
{
    int a, b, c;
    int n1, n2, n3;

    while (1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a + b + c == 0)
            break;
        n1 = a * a;
        n2 = b * b;
        n3 = c * c;

        if (n1 + n2 == n3 || n1 + n3 == n2 || n2 + n3 == n1)
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}