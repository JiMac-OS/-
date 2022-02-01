#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char *data;
    struct node *next;
    struct node *prev;
} Node;
// 이중연결리스트는 head, tail 모두 설정.
Node *head = NULL;
Node *tail = NULL;
int size = 0;
void add_after(Node *pre, char *item);
void remove1(Node *p);
void add_ordered_list(char *item);
int main(void)
{
    // 기본적인 노드 삽입 예시.
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *p;
    new_node->data = "jiman";
    new_node->next = p;
    new_node->prev = p->prev;
    p->prev = new_node;
    p->prev->next = new_node;

    // 기본적인 노드 삭제 예시.
    p->next->prev = p->prev;
    p->prev->next = p->next;

    return 0;
}
void add_after(Node *pre, char *item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL && pre == NULL) // 리스트에 new_node 하나뿐인 경우
    {
        head = new_node;
        tail = new_node;
    }
    else if (pre == NULL) //리스트에 head만 있는 경우
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if (pre == tail) // 꼬리 뒤에 삽입하는 경우
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    else // 중간에 삽입하는 경우
    {
        new_node->next = pre->next;
        new_node->prev = pre;
        pre->next->prev = new_node;
        pre->next = new_node;
    }
    size++;
}
void remove1(Node *p)
{
    if (p->prev == NULL && p->next == NULL)
    {
        head = NULL;
        tail = NULL;
        free(p);
    }
    else if (p->prev == NULL)
    {
        head = p->next;
        head->prev = NULL;
        free(p);
    }
    else if (p->next == NULL)
    {
        tail = p->prev;
        p->next = NULL;
        free(p);
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
    size--;
}
void add_ordered_list(char *item)
{
    Node *p = tail;
    while (p != NULL && strcmp(p->data, item) > 0)
        p = p->prev;

    add_after(p, item);
}