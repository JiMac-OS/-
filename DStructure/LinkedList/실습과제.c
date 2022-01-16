#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *head = NULL;
Node *add_first(int num)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = num;
    temp->next = head;
    head = temp;

    return head;
}
Node *add_after(Node *prev, int num)
{

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = num;
    temp->next = prev->next;
    prev->next = temp;

    return temp;
}
Node *get_node(int index)
{
    if(index<0)return NULL;
    Node *p = head;
    for(int i=0;i<index && p!=NULL;i++)
    {
        p=p->next;
    }
    return p;
}
void add_index(index,num)
{
    Node *tmp;
    if(index==0)
    {
        tmp = add_first(num);
    }
    Node *prev = get_node(index-1);
    if(prev!=NULL)
    {
        tmp = add_after(prev,num);
    }
}
int main(void)
{

    while (1)
    {
        char arr[100];
        char *sentence;
        int num;
        printf("$ ");
        scanf("%s", arr);
        sentence = strdup(arr);
        if (strcmp(sentence, "exit") == 0)
            break;
        if (strcmp(arr, "create") == 0)
        {
            int cnt = 0;
            Node *prev;
            while (1)
            {
                scanf("%d", &num);
                cnt++;
                if (num == 0)
                    break;
                if (cnt == 1)
                {
                    prev = add_first(num);
                }
                else
                {
                    prev = add_after(prev, num);
                }
            }
        }
        if(strcmp(arr, "add -f") == 0)
        {
            scanf("%d",&num);
            add_first(num);
        }
        if(strcmp(arr, "add -i") == 0)
        {
            int index;
            scanf("%d %d",&index,&num);
            add_index(index,num);
        }
        if(strcmp(arr, "remove -i") == 0)
        {
            scanf("%d",&num);

        }

    }

    Node *p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}