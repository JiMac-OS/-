#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char *data; //문자들을 저장하는 스텍이라고 가정하자.
    struct node *next;
} Node;
Node *top = NULL;
void push(char *item) // == add_first
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = item;
    p->next = top;
    top = p;
}
char *pop()
{
    if (is_empty())
        return NULL;
    char *result = top->data;
    top = top->next;
    return result;
}
char *peek()
{
    if (is_empty())
        return;
    return top->data;
}
int is_empty()
{
    return top == NULL;
}