// 어떤 노드 뒤에 새로운 노드 삽입하기
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
int main(void)
{
    return 0;
}