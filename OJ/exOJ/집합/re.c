#include <stdio.h>
#include <stdlib.h>
typedef struct SET
{
    int elem;
    struct SET *next;
} set;
void addelem(set *L, int e);
int member(set *L, int e);
int subset(set *A, set *B);
int main()
{
    int n, e;
    set *A = NULL;
    set *B = NULL;
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
                addelem(A, e);
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
            addelem(B, e);
    }
    printf("%d\n", subset(A, B));
    return 0;
}
void addelem(set *L, int e)
{
    set *p, *q;
    p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    q = (set *)malloc(sizeof(set));
    p->next = q;
    q->elem = e;
    q->next = NULL;
}
int member(set *L, int e)
{
    set *p;
    p = L;
    if (L == NULL)
        return 0;
    while (1)
    {
        if (p->elem < e)
        {
            if (p->next == NULL)
                return 0;
            else
                p = p->next;
        }
        else if (p->elem > e)
        {
            return 0;
        }
        else
            return 1;
    }
}
int subset(set *A, set *B)
{
    set *p;
    p = A;
    if (A == NULL)
        return 0;
    while (1)
    {
        if (member(B, p->elem))
        {
            if (p->next == NULL)
                return 0;
            else
                p = p->next;
        }
        else
            return p->elem;
    }
}