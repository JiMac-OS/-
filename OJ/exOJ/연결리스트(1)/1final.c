#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char elem;
    struct node *next;
    struct node *prev;
} Node;
Node *head, *tail;
int n = 0;
void init()
{
    head = (Node *)malloc(sizeof(Node));
    tail = (Node *)malloc(sizeof(Node));
    head->elem = 0;
    tail->elem = 0;

    head->next = tail;
    tail->prev = head;
}
void get(Node *list, int r)
{
    if (r < 1 || r > n)
    {
        printf("invalid position\n");
        return;
    }

    Node *p = list;
    for (int i = 0; i < r; i++)
        p = p->next;

    printf("%c\n", p->elem);
}
void print(Node *list)
{
    Node *p = list->next;
    while (p != tail)
    {
        printf("%c", p->elem);
        p = p->next;
    }
}
void add_after(Node *list, int r, char e)
{

    if (r < 1 || r > n + 1)
    {
        printf("invalid position\n");
        return;
    }
    Node *p;
    p = list;
    for (int i = 0; i < r; i++)
        p = p->next;

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->elem = e;
    new_node->next = p;
    new_node->prev = p->prev;
    p->prev->next = new_node;
    p->prev = new_node;
    n++;
}
void delete (Node *list, int r)
{
    if (r < 1 || r > n)
    {
        printf("invalid position\n");
        return;
    }

    Node *p = list;
    for (int i = 0; i < r; i++)
        p = p->next;

    p->next->prev = p->prev;
    p->prev->next = p->next;
    n--;
    free(p);
}
int main(void)
{
    init();
    int N;
    int i;
    char calc, e;
    int r;
    scanf("%d", &N);
    getchar();
    for (i = 0; i < N; i++)
    {
        scanf("%c", &calc);
        getchar();
        if (calc == 'A')
        {
            scanf("%d %c", &r, &e);
            getchar();
            add_after(head, r, e);
        }
        else if (calc == 'D')
        {
            scanf("%d", &r);
            getchar();
            delete (head, r);
        }
        else if (calc == 'G')
        {
            scanf("%d", &r);
            getchar();
            get(head, r);
        }
        else if (calc == 'P')
        {
            print(head);
            printf("\n");
        }
    }

    return 0;
}