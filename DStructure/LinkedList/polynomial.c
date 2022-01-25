#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POLYS 100
#define BUFFER_LENGTH 100
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

    if (q == NULL) // 맨 앞에 삽입하는 경우
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
int eval(Polynomial *poly, int x) // 다항식의 값을 계산하는 함수
{
    int result = 0;
    Term *t = poly->first;
    while (t != NULL)
    {
        result += eval(t, x);
        t = t->next;
    }
    return result;
}
int eval(Term *term, int x)
{
    int result = term->coef;
    for (int i = 0; i < term->expo; i++)
    {
        result *= x;
    }
    return result;
}
void print_term(Term *pTerm)
{
    printf("%dx^%d", pTerm->coef, pTerm->expo);
}
void print_poly(Polynomial *p)
{
    printf("%c=", p->name);
    Term *t = p->first;
    while (t != NULL)
    {
        print_term(t);
        printf("+");
        t = t->next;
    }
}
int read_line(FILE *fp, char str[], int n)
{
    int ch, i = 0;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF)
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
void handle_definition(char *expression)
{
    erase_blanks(expression);

    char *f_name = strtok(expression, "=");
    if (f_name = NULL || strlen(f_name) != 1)
    {
        printf("Unsupported command.");
        return 0;
    }
    char *exp_body = strtok(NULL, "=");
    if (exp_body == NULL || strlen(exp_body) <= 0)
    {
        printf("Invalid expression format.--");
        return;
    }
}
void process_commend()
{
    char command_line[BUFFER_LENGTH];
    char copied[BUFFER_LENGTH];
    char *command, *arg1, *arg2;

    while (1)
    {
        printf("$ ");
        if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
            continue;
        strcpy(copied, command_line); //입력 라인을 복사해 둔다.
        command = strtok(command_line, " ");
        if (strcmp(command, "print") == 0)
        {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL)
            {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_print(arg1[0]);
        }
        else if (strcmp(command, "calc") == 0)
        {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL)
            {
                printf("Invalid arguments.\n");
                continue;
            }
            arg2 = strtok(NULL, " ");
            if (arg2 == NULL)
            {
                printf("Invalid arguments.\n");
                continue;
            }
            handle_calc(arg1[0], arg2);
        }
        else if (strcmp(command, "exit") == 0)
            break;
        else
            handle_definition(copied);
    }
}

int main(void)
{

    return 0;
}