// 어떤 노드 뒤에 새로운 노드 삽입하기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *data;
    struct node *next; //자기참조형 구조체
};
typedef struct node Node;
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
int main(void)
{

    return 0;
}