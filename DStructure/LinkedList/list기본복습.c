#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 연결리스트 맨 앞에 새로운 노드를 삽입하기.
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
    {
        return NULL;
    }
    else
    {
        prev->next = tmp->next;
        return tmp;
    }
}
Node *find(char *word)
{ //입력된 문자열 word와 동일한 단어를 저장한 노드를 찾아서 그 노드의 주소를 반환한다.
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
    // 노드를 삭제하기 위해서는 삭제할 노드가 아니라 직전 노드의 주소가 필요하다.
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
        return remvoe_first();
    else
        return remove_after(q);
    // q는 항상 p의 직전 노드를 가리킴.
    // p가 첫번째 노드일 경우 q는 NULL이다.
}
void add_to_ordered_list(char *item)
// 연결리스트에 데이터들이 오름차순으로 정렬되어 있다는 가정하에서 새로운 데이터를 삽입한다.
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
        add_after(item, q);
}
int main(void)
{

    char *item = (char *)malloc(sizeof(char));
    scanf("%s", item);
    add_first(item);
    add_after("jihwan", head);
    add_after("apple", head->next);
    add_after("pineapple", head->next->next);
    add(1, "libery");

    Node *p = head;
    while (p != NULL)
    {
        printf("%s\n", p->data);
        p = p->next;
    }
    free(p);
    free(item);
    return 0;
}