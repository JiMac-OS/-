#include <stdio.h>
int main(void)
{
    long t, x, y;
    scanf("%ld", &t);

    for (int i = 0; i < t; i++)
    {
        long distance;
        int count = 0;
        int move = 1;
        scanf("%ld %ld", &x, &y);
        distance = y - x;

        while (distance / 2 >= move)
        {
            distance -= move * 2;
            count += 2;
            move++;
        }

        if (distance >= 1 && distance <= move)
        {
            count++;
        }
        else if (distance > move)
        {
            count += 2;
        }
        printf("%d\n", count);
    }

    return 0;
}