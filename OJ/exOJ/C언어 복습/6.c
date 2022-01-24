#include <stdio.h>
typedef struct sc
{
    char name[10];
    int score;
} SCORE;
int main(void)
{
    SCORE sc[5], *p;
    int sum = 0;

    for (p = sc; p < sc + 5; p++)
    {
        scanf("%s %d", p->name, &p->score);
        sum += p->score;
    }

    for (p = sc; p < sc + 5; p++)
    {
        if ((float)sum / 5 >= p->score)
        {
            printf("%s\n", p->name);
        }
    }

    return 0;
}