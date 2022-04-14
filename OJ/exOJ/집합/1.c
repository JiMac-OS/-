#include <stdio.h>
#include <stdlib.h>
typedef struct SET
{
    int elem;
    struct SET *next;
} set;
int member(set *L, int e)
{
    set *p;
    p = L;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        while (p != NULL)
        {
            if (p->elem > e) // B>A
                return 0;
            else if (p->elem == e) //B==A
                return 1;
            else // B<A
                p = p->next;
        }
    }
    return 0;
}
int subset(set *A, set *B)
{
    int m;
    set *p;
    p = A;
    if (A == NULL)
        return 0;
    while (p != NULL)
    {
        m = member(B, p->elem);
        if (m == 0)
            return p->elem;
        else
            p = p->next;
    }
    return 0;
}
void addelem(set *x, int e)
{
    set *p;
    set *q;
    p = x;
    while (p->next != NULL)
    {
        p = p->next;
    }
    q = (set *)malloc(sizeof(set));
    p->next = q;
    q->elem = e;
    q->next = NULL;
}
int main()
{
    int n, e;
    set *A = NULL;
    set *B = NULL;
    set *p;
    int ans;
    scanf("%d", &n);
    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &e);
            if (A == NULL)
            {
                A = (set *)malloc(sizeof(set));
                A->elem = e;
                A->next = NULL;
            }
            else
            {
                addelem(A, e);
            }
        }
    }
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        if (B == NULL)
        {
            B = (set *)malloc(sizeof(set));
            B->elem = e;
            B->next = NULL;
        }
        else
        {
            addelem(B, e);
        }
    }

    printf("%d\n", subset(A, B));

    return 0;
}