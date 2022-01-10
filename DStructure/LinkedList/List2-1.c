//복습
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *data;
    struct node *next;
};
typedef struct node Node;
Node *head = NULL;
void add_first(char *item)
{
    Node *tmp=(Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}
void add_first(Node **ptr,char *item)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = *ptr;
    *ptr = tmp;
}
Node *add_first(char *item, Node *head)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp ->data = item;
    tmp ->next = head;
    return tmp;

}
int main(void)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = "jihwan";
    tmp->next = head;
    head = tmp;
    return 0;
}
