// 첫번째 노드의 삭제
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
Node * remove_first()
{
    if(head==NULL)return NULL;
    else
    {
        // head == 전역변수
        Node *tmp = head;
        head = head->next;
        return tmp;
    }
    // 연결리스트의 첫번째 노드를 삭제하고 그 노드의 주소를 반환한다.
}
int main(void)
{
    
    return 0;
}