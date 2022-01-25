#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 100
typedef struct term
{
    int coef;
    int expo;
    struct term *next;
} Term;
typedef struct polynomial
{
    char name;
    Term *first;
    int size;
} Polynomial;
Polynomial *polys[MAX_POLYS];
//polys는 다항식들에 대한 포인터 배열이다.
int n = 0; //저장된 다항식의 개수이다.
Term *create_term_instance()
{
    Term *t = (Term *)malloc(sizeof(Term));
    t->coef = 0;
    t->expo = 0;
    t->next = NULL;
    return t;
}
Polynomial *create_polynomial_instance(char name)
{
    Polynomial *ptr_poly = (Polynomial *)malloc(sizeof(Polynomial));
    ptr_poly->name = name;
    ptr_poly->size = 0;
    ptr_poly->first = NULL;
    return ptr_poly;
}
// 동적으로 생성된 객체를 적절하게 초기화해주지 않는 것이 종종 프로그램의 오류를 야기한다. 이렇게 객체를 생성하고 기본값으로 초기화해주는 함수를 따로 만들어 사용하는 것은 좋은 방법이다.
void add_term(int c, int e, Polynomial *poly)
{
    if (c == 0)
        return;
    Term *p = poly->first;
    Term *q = NULL;
    while (p != NULL && p->expo > e)
    {
        q = p;
        p = p->next;
    }
    if (p != NULL && p->expo == e) //동일 차수의 항이 존재하는 경우
    {
        p->coef += c;
        if (p->coef == 0) // 더했더니 계수가 0이 되는 경우
        {
            if (q == NULL) // 첫번째 항의 차수가 가장 큰 경우.
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

    if (q == NULL) // 맨 앞에 삽입하는 경우
    {
        term->next = poly->first;
        poly->first = term;
    }
    else // q의 뒤 p의 앞에 삽입
    {
        term->next = p;
        q->next = term;
    }
    poly->size++;
}

int eval1(Term *term, int x)
{
    int result = term->coef;
    for (int i = 0; i < term->coef; i++)
    {
        result *= x;
    }
    return result;
}
int eval2(Polynomial *poly, int x)
{
    int result = 0;
    Term *t = poly->first;
    while (t != NULL)
    {
        result += eval1(t, x);
        t = t->next;
    }
    return result;
}
