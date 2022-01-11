//연결리스트 순회하기
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
Node *find(char *word)
{
    Node *p = head;
    while (p != NULL)
    {
        if (strcmp(p->data, word) == 0)
            return p;
        p = p->next;
    }
    return NULL;
    //연결리스트의 노드들을 처음부터 순서대로 방문하는 것을 순회한다고 말한다. 이 함수는 입력된 문자열 word와 동일한 단어를 저장한 노드를 찾아서 그 노드의 주소를 반환한다. 그것을 위해서 연결리스트를 순회한다.
}

Node *get_node(int index)
{
    if (index < 0)
        return NULL;
    Node *p = head;
    for (int i = 0; i < index && p != NULL; i++)
        p = p->next;
    return p;
    // 연결리스트의 index번째 노드의 주소를 반환한다.
}