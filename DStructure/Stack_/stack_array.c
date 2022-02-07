#include <stdio.h>
#include <string.h>
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY]; // 스택에 저장되는 데이터의 타입을 문자라고 가정하자.
int top = -1;             // index of the top element

void push(char ch)
{
    if (is_full()) // 스택이 가득차면 더이상 push할 수 없다.
        return;
    top++;
    stack[top] = ch;
}
char pop() // pop을 호출하기 전에 먼저 empty인지 검사해야 한다.
{
    char tmp = stack[top];
    top--;
    return tmp;
}
char peek() // peek을 호출하기 전에 먼저 empty인지 검사해야 한다.
{
    return stack[top];
}
int is_empty()
{
    return top == -1;
}
int is_full()
{
    return top == MAX_CAPACITY - 1;
}