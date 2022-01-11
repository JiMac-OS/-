// index번째 노드를 삭제하고, 그 노드에 저장된 데이터를 반환한다.
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
Node *remove_first()
{
    if (head == NULL)
        return NULL;
    else
    {
        // head == 전역변수
        Node *tmp = head;
        head = head->next;
        return tmp;
    }
    // 연결리스트의 첫번째 노드를 삭제하고 그 노드의 주소를 반환한다.
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
Node *get_node(int index)
{
    if (index < 0)
        return NULL;

    Node *p = head;
    for (int i = 0; i < index && p != NULL; i++)
    {
        p = p->next;
    }
    return p;
}
Node *remove(int inex)
{
    if (index < 0)
        return NULL;

    if (index == 0)
        return remove_first();

    Node *prev = get_node(index - 1);
    if (prev == NULL)
        return NULL;
    else
    {
        return remove_after(prev);
    }
}