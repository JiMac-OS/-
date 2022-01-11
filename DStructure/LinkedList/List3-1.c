//어떤 노드의 다음 노드 삭제하기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char *data;
    struct node *next;
};
typedef struct node Node;
Node *head = NULL;
Node *remove_after(Node *prev)
{
    Node *tmp = prev->next;
    if (tmp == NULL)
        return NULL;
    else
    {
        prev->next = tmp->next;
        return tmp;
    }
    // 단순연결리스트에 어떤 노드를 삭제할 떄는 삭제할 노드의 바로 앞 노드의 주소가 필요하다. 삭제할 노드의 주소만으로는 삭제할 수 없다.
}
