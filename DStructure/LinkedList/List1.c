//리스트 예제
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *data;

    struct node *next; //자기참조형 구조체
};
typedef struct node Node;
Node *head = NULL; //연결리스트의 첫 번째 노드의 주소를 저장할 포인터이다.
int main(void)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = "Tuseday";
    head->next = NULL;

    Node *q = (Node *)malloc(sizeof(Node));
    q->data = "Thursday";
    q->next = NULL;
    head->next = q;

    q = (Node *)malloc(sizeof(Node));
    q->data = "Monday";
    q->next = head;
    head = q;

    Node *p = head;
    while (p != NULL)
    {
        printf("%s\n", p->data);
        p = p->next;
    }

    return 0;
}