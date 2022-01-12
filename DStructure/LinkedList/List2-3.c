//연결리스트의 데이터들이 오름차순으로 정렬되어 있다는 가정하에서 새로운 데이터를 삽입한다.
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
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}
int add_after(Node *prev, char *item)
{
    if (prev == NULL)
        return 0;

    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = prev->next;
    prev->next = tmp;
    return 1;
    //연결리스트에 새로운 노드를 삽입할 때 삽입할 위치의 바로 앞 노드의 주소가 필요하다. 즉 어떤 노드의 뒤에 삽입하는 것은 간단하지만, 반대로 어떤 노드의 앞에 삽입하는 것은 간단하지 않다.
}
Node *get_node(int index)
{
    if (index < 0)
        return NULL;
    Node *p = head;
    for (int i = 0; i < index && p != NULL; i++)
        p = p->next;
    return p;
    // 연결리스트의 index번째 노드의 주소를 반환한다.
}
void add_to_ordered_list(char *item)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL && strcmp(p->data, item) <= 0)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
        add_first(item);
    else
        add_after(q, item);
}