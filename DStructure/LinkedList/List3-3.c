//입력된 스트링을 저장한 노드를 찾아 삭제한다. 삭제된 노드에 저장된 스트링을 반환한다.
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
/* Node *remove(char *item)
{
    Node *p = head;
    while (p != NULL && strcmp(p->data, item) != 0)
    {
        p = p->next;
    }
    // 삭제할 노드를 찾았음. 하지만 노드를 삭제하기 위해서는 삭제할 노드가 아니라 직전 노드의 주소가 필요하다.
} */

Node *remove(char *item) // 2개의 포인터를 활용한다.
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

    // q는 항상 p의 직전 노드를 가리킴. p가 첫번째 노드일 경우 q는 NULL이다.
}