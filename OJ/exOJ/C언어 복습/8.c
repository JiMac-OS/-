#include <stdlib.h>
#include <stdio.h>
typedef struct s
{
    char name[8];
    int k, e, m;
    double avg;
} student;
int main(void)
{
    int N;
    scanf("%d", &N);
    student *info = (student *)malloc(sizeof(student) * N);
    student *p;

    for (p = info; p < info + N; p++)
    {
        int sum = 0;
        scanf("%s %d %d %d", p->name, &p->k, &p->e, &p->m);
        sum = p->k + p->e + p->m;
        p->avg = (double)sum / 3;
        printf("%s %.1lf", p->name, p->avg);
        if (p->k >= 90 || p->e >= 90 || p->m >= 90)
            printf(" GREAT");
        if (p->k < 70 || p->e < 70 || p->m < 70)
            printf(" BAD");

        printf("\n");
    }

    free(info);

    return 0;
}