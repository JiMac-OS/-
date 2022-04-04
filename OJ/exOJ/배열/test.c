#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *data;
    struct node *next;
} Node;
Node *head = NULL;
void add_first(char *item)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = head;
    head = temp;
}
int add_after(char *item, Node *prev)
{
    if (prev == NULL)
        return 0;

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = prev->next;
    prev->next = temp;
    return 1;
}
Node *remove_first()
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *tmp = head;
        head = head->next;
        return tmp;
    }
}
Node *remove_after(Node *prev)
{
    Node *tmp = prev->next;
    if (tmp == NULL)
        return NULL;
    else
    {
        prev->next = tmp->next;
        return tmp;
    }
}
Node *find(char *word)
{
    Node *p = head;
    while (p != NULL)
    {
        if (strcmp(p->data, word) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}
Node *get_node(int index)
{
    if (index < 0)
        return NULL;
    Node *p = head;
    for (int i = 0; i < index && p != NULL; i++)
        p = p->next;
    return p;
}
int add(int index, char *item)
{
    if (index < 0)
        return 0;
    if (index == 0)
    {
        add_first(item);
        return 1;
    }
    Node *prev = get_node(index - 1);
    if (prev != NULL)
    {
        add_after(item, prev);
        return 1;
    }
    return 0;
}
char *remove_LV1(int index)
{
    if (index < 0)
        return NULL;
    if (index == 0)
        return remove_first();
    Node *prev = get_node(index - 1);
    if (prev == NULL)
        return NULL;
    else
        return remove_after(prev);
}
char *remove_LV2(char *item)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL && strcmp(p->data, item) != 0)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
        return NULL;
    if (q == NULL)
        return remove_first();
    else
        return remove_after(q);
}