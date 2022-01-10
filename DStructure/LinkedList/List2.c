// 연결리스트의 맨 앞에 새로운 노드 삽입하기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *data;
    struct node *next; //자기참조형 구조체
};
typedef struct node Node;
Node *head = NULL; //연결리스트의 첫 번째 노드의 주소를 저장할 포인터이다.(전역변수)
void add_first(char *item)
{ // 맨 앞에 새로운 노드 삽입 함수로 코딩한 것.
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = head;
    head = temp; //head가 전역변수이기 때문에 가능하다.
}

void add_first(char *item, Node **ptr_head)
// 첫번째 노드를 가리키는 포인터 head가 전역변수가 아닌 경우 1
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = *ptr_head;
    *ptr_head = temp;
// 이렇게 구현할 경우 이 함수는 다음과 같이 호출해야 한다.
// add_first(item_to_store,&head)
}

Node *add_first(Node *head, char *item)
// 첫번째 노드를 가리키는 포인터 head가 전역변수가 아닌 경우 2
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = head;
    return temp;
// 이렇게 구현할 경우 이 함수는 다음과 같이 호출해야 한다.
// add_first(head, item_to_store)
}

int main(void)
{
    Node *tmp = (Node *)malloc(sizeof(Node)); //연결리스트의 맨 앞에 새로운 노드 삽입하기
    tmp->data = "Ann";
    tmp->next = head;
    head = tmp;
    return 0;
}