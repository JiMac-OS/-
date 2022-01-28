#include <stdio.h>
#include <stdlib.h>
// 꼭 블로그에 남기자.
typedef struct node
{
    char elem;
    struct node *next;
    struct node *prev;
} Node;
void add(Node *list, int r, char e);
void print(Node *head);
void delete (Node *list, int r);
int main(void)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));
    head->next = tail;
    tail->prev = head;
    add(head, 1, 'S');
    add(head, 2, 't');
    add(head, 3, 'a');
    add(head, 2, 'r');
    print(head);

    return 0;
}
void print(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
}
void add(Node *list, int r, char e)
{
    Node *p = list;
    for (int i = 0; i < r; i++)
    {
        if (p->next == NULL)
        {
            printf("invaild position\n");
            return;
        }
        p = p->next;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->elem = e;
    new_node->prev = p->prev;
    new_node->prev->next = new_node;
    new_node->next = p;
    p->prev = new_node;
    // head , tail은 값 취급 x
    // 그냥 next , prev만 있다고 생각하고 코딩하자 .
}
void delete (Node *list, int r)
{
}