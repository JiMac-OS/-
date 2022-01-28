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
Node *get(Node *list, int r);
int main(void)
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));
    head->next = tail;
    tail->prev = head;

    int n, r;
    char e, c;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &c);
        getchar();
        switch (c)
        {
        case 'A':
            scanf("%d %c", &r, &e);
            getchar();
            add(head, r, e);
            break;
        case 'D':
            scanf("%d", &r);
            getchar();
            delete (head, r);
            break;
        case 'G':
            scanf("%d", &r);
            getchar();
            Node *p = get(head, r);
            if (p == tail)
                printf("invalid position\n");
            else
                printf("%c\n", p->elem);
            break;
        case 'P':
            print(head);
        default:
            break;
        }
    }

    return 0;
}
Node *get(Node *list, int r)
{
    Node *p = list;
    for (int i = 0; i < r; i++)
    {
        if (p->next == NULL)
        {
            printf("invalid position\n");
            return NULL;
        }
        p = p->next;
    }
    return p;
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
    Node *p = get(list, r);

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
    Node *p = get(list, r);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    if (p->next == NULL || r == 0)
    {
        printf("invalid position\n");
        return;
    }
    free(p);
}

/* 
9 
A 1 D 
A 2 a 
A 3 y 
D 1 
P 
G 3 
A 1 S 
P 
G 3 
 */

//https://engeon.tistory.com/75 꼭 참고하자