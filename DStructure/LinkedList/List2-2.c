//연결리스트의 index번째 위치에 새로운 노드를 만들어서 삽입.
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
        add_after(prev, item);
        return 1;
    }
    return 0;
    // 연결리스트에서 index번째 자리에 새로운 노드를 추가할 때 그 인덱스가 0인경우, 0이 아닌 경우(추가된 위치가 맨 앞인 경우와 그렇지 않은 경우)를 별개의 케이스로 처리를 해줘야한다. 중요..
}