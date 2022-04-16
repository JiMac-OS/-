#include <stdio.h>
#include <stdlib.h>
typedef struct SET
{
    int elem;
    struct SET *next;
} set;
void addelem(set *L, int e);
set *Union(set *A, set *B);
set *Intersect(set *A, set *B);
void print(set *c);
int main()
{
    int n, e;
    set *A, *B;
    set *p, *q;
    A = (set *)malloc(sizeof(set));
    A->next = NULL;
    B = (set *)malloc(sizeof(set));
    B->next = NULL;

    scanf("%d", &n);
    p = A;
    q = B;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        addelem(p, e);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        addelem(q, e);
    }

    print(Union(A, B));
    printf("\n");
    print(Intersect(A, B));
    printf("\n");

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
set *Union(set *A, set *B)
{
    set *C = (set *)malloc(sizeof(set));
    C->next = NULL;
    set *p = C;
    set *a = A->next, *b = B->next;

    if (a == NULL && b == NULL)
        return NULL;

    if (a == NULL)
        return B;
    else if (b == NULL)
        return A;

    while (a != NULL && b != NULL)
    {
        if (a->elem > b->elem)
        {
            addelem(p, b->elem);
            b = b->next;
        }
        else if (a->elem < b->elem)
        {
            addelem(p, a->elem);
            a = a->next;
        }
        else
        {
            addelem(p, a->elem);
            a = a->next;
            b = b->next;
        }
    }
    while (a != NULL)
    {
        addelem(p, a->elem);
        a = a->next;
    }
    while (b != NULL)
    {
        addelem(p, b->elem);
        b = b->next;
    }
    return p;
}
set *Intersect(set *A, set *B)
{
    set *C = (set *)malloc(sizeof(set));
    C->next = NULL;
    set *p = C;
    set *a = A->next, *b = B->next;

    if (a == NULL || b == NULL)
        return NULL;

    while (a != NULL && b != NULL)
    {
        if (a->elem < b->elem)
        {
            a = a->next;
        }
        else if (a->elem > b->elem)
        {
            b = b->next;
        }
        else
        {
            addelem(p, a->elem);
            a = a->next;
            b = b->next;
        }
    }
    return p;
}
void print(set *C)
{
    if (C == NULL)
    {
        printf(" 0");
        return;
    }

    set *p = C->next;
    while (p != NULL)
    {
        printf(" %d", p->elem);
        p = p->next;
    }
}
