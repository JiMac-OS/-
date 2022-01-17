#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 100
struct term
{
    int coef; //계수
    int expo; //지수
    struct term *next;
};
typedef struct term Term;
typedef struct polynomial
{
    char name;
    Term *first;
    int size;
} Polynomial;
Polynomial *polys[MAX_POLYS];
int n = 0;
Term *create_term_instance()
{
    Term *t = (Term *)malloc(sizeof(Term));
    t->coef = 0;
    t->expo = 0;
    return t;
}
Polynomial *create_polynominal_instance(char name)
{
    Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
    ptr_poly->name = name;
    ptr_poly->size = 0;
    ptr_poly->first = NULL;
    return ptr_poly;
}
void add_term(int c, int e, Polynomial *poly)
{
    if (c == 0)
        return;
    Term *p = poly->first, *q = NULL;
    while (p != NULL && p->expo > e)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL && p->expo == e) //동일차수항이 존재하는경우
    {
        p->coef += c;
        if (p->coef == 0) // 더했더니 계수가 0이 되는 경우
        {
            if (q == NULL)
                poly->first = p->next;
            else
                q->next = p->next;

                poly->size--;
                free(p);
        }
        return;
    }

    Term *term = create_term_instance();
    term->coef = c;
    term->expo = e;

    if(q==NULL) // 맨 앞에 삽입하는 경우
    {
        term->next = poly->first;
        poly->first = term;
    }
    else
    {
        term->next = p;
        q->next = term;
    }
    poly->size++;    
}
int main(void)
{

    return 0;
}