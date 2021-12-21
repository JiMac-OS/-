#include <stdio.h>
#include <string.h>

int main(void)
{
    int X, a, b;
    int cnt = 1, check;
    int gap;
    int i = 2, j = 3;
    scanf("%d", &X);
    if (X == 1)
    {
        printf("1/1\n");
        return 0;
    }

    while (1)
    {
        gap = j - i;

        if (gap % 2 != 0)
        {
            if (X >= i && X <= j)
            {
                check = 0;
                break;
            }
        }
        else
        {
            if (X >= i && X <= j)
            {
                check = 1;
                break;
            }
        }
        cnt++;
        i = j + 1;
        j = gap + i + 1;
    }

    if (check == 0)
    {

        for (a = 1, b = cnt + 1;; i++, a++, b--)
        {
            if (i == X)
            {
                printf("%d/%d\n", a, b);
                break;
            }
        }
    }
    else if (check == 1)
    {
        a = cnt + 1;
        b = 1;
        for (a = cnt + 1, b = 1;; i++, a--, b++)
        {
            if (i == X)
            {
                printf("%d/%d\n", a, b);
                break;
            }
        }
    }

    return 0;
}