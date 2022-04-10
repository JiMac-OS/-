#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coef;
    int exp;
    //다음 노드의 주소를 가르킬 구조체 포인터
    struct node *link;
} ListNode;
typedef struct head
{
    ListNode *head;
} ListHead;
ListHead *createLinkedList()
{
    ListHead *L;
    L = (ListHead *)malloc(sizeof(ListHead));
    L->head = NULL;
    return L;
}
void addLastNode(ListHead *L, int coef, int exp)
{
    ListNode *newnode;
    ListNode *p;
    newnode = (ListNode *)malloc(sizeof(ListNode));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->link = NULL;
    if (L->head == NULL)
    {
        L->head = newnode;
        return;
    }
    else
    {
        p = L->head;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = newnode;
    }
}
void addPoly(ListHead *A, ListHead *B, ListHead *C)
{
    ListNode *pA = A->head;
    ListNode *pB = B->head;

    int sum = 0;

    while (pA && pB)
    {
        if (pA->exp == pB->exp)
        {
            sum = pA->coef + pB->coef;
            addLastNode(C, sum, pA->exp);
            pA = pA->link;
            pB = pB->link;
        }
        else if (pA->exp > pB->exp)
        {
            addLastNode(C, pA->coef, pA->exp);
            pA = pA->link;
        }
        else
        {
            addLastNode(C, pB->coef, pB->exp);
            pB = pB->link;
        }
    }
    for (; pA != NULL; pA = pA->link)
        addLastNode(C, pA->coef, pA->exp);
    for (; pB != NULL; pB = pB->link)
        addLastNode(C, pB->coef, pB->exp);
}
void printPoly(ListHead *L)
{
    ListNode *p = L->head;
    while (p->link != NULL)
    {
        printf(" %d %d", p->coef, p->exp);
        p = p->link;
    }
}
int main()
{
    int N;
    int coef, exp;
    ListHead *A, *B, *C;
    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &coef, &exp);
        getchar();
        addLastNode(A, coef, exp);
    }
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &coef, &exp);
        getchar();
        addLastNode(B, coef, exp);
    }
    addPoly(A, B, C);
    printPoly(C);
    printf("\n");

    return 0;
}
