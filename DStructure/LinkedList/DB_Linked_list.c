// 이중 연결 리스트
// 각각의 노드가 다음노드와 이전노드의 주소를 가지는 연결리스트
// 양방향 순회가 가능하다.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *data; //각 노드의 하나의 문자열이 저장된다고 가정하자.
    struct node *next;
    struct node *prev;
};
typedef struct node Node;
Node *head;
Node *tail;
int size = 0;
// search, add, remove, travers
void add_after(Node *pre, char *item)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (pre == NULL && head == NULL) //pre가 유일한 노드인 경우
    {
        head = new_node;
        tail = new_node;
    }
    else if (pre == NULL) // pre가 head인 경우 맨 앞에 삽입한다는 의미.
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    else if (pre == tail) // pre가 tail인 경우 맨 뒤에 삽입하라는 의미.
    {
        new_node->next = NULL;
        new_node->prev = tail;
        tail = new_node;
    }
    else // 그 밖의 일반적인 경우 - in the middle
    {
        new_node->prev = pre;
        new_node->next = pre->next;
        pre->next->prev = new_node;
        pre->next = new_node;
    }
    size++;
}
void remove(Node *p)
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
        tail->next = NULL;
        free(p);
    }
    else
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
}
void arr_ordered_list(char *item)
{
    Node *p = tail;                                // 뒤에서 앞으로 순회
    while (p != NULL && strcmp(item, p->data) < 0) //자신보다 큰 값의 앞 노드에 추가
        p = p->prev;

    add_after(p, item);
    // 1. 리스트가 비어 있을 때
    // 2. 리스트의 맨 앞에 삽입할 때
    // 3. 리스트의 맨 뒤에 삽입할 때
    // 4. 중간에 삽입할 때 모두 가능
}
int main(void)
{
    // p가 가리키는 노드 앞에 새로운 노드를 삽입하는 경우.
    // 순서가 즁요하다.
    Node *p;
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = "jihwan";
    new_node->next = p;
    new_node->prev = p->prev;
    p->prev->next = new_node;
    p->prev = new_node;

    //p가 가리키는 노드를 삭제하는 경우
    p->prev->next = p->next;
    p->next->prev = p->prev;
    // 개념은 어렵지 않지만 문제를 구현하는 것이 생각보다 난이도가 높다.
    // 학교수업을 재미있게 들으려면 기본적인 자료구조 알고리즘이 되어있어야 한다.
    // 그것이 가능하다면 내가 원하는 언어를 빠르게 습득할 수 있다.
    // 원하는 프로그램을 만들기 수월해진다.
    // 알고리즘을 재미있게 공부하려면 개념을 외우는 것이 아니라, 많은 문제를 접하면서 모르는 것을 그떄 그때 찾아보고, 그림을 그려보며 코드를 구현하는 것이다. 많은 구현, 반복을 해보다 보면 자동으로 중요한 개념들은 암기가 된다. 사실 모든 개발 공부가 그러하다. 반복이 어느경지에 오르는 가장 빠른 방법이다.
    return 0;
}