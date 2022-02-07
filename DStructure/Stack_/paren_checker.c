#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100

/* 
push: 스택에 새로운 원소를 삽입하는 연산
pop: 스택의 top에 있는 원소를 스택에서 제거하고 반환
peek: 스택 top의 원소를 제거하지 않고 반환
empty: 스택이 비어있는지 검사
 */

char OPEN[] = "([{";
char CLOSE[] = ")]}";
int is_balanced(char *expr);
int is_open(char ch);
int is_close(char ch);

int main(void)
{
    char expr[MAX_LENGTH];
    scanf("%s", expr);
    if (is_balanced(expr))
        printf("%s: balanced.\n", expr);
    else
        printf("%s: unbalanced.\n", expr);
    return 0;
}
int is_balanced(char *expr)
{
    int balanced = 1;
    int index = 0;
    while (balanced && index < strlen(expr))
    {
        char ch = expr[index];
        if (is_open(ch) > -1)
            push(ch);
        else if (is_close(ch) > -1)
        {
            if (is_empty())
            {
                balanced = 0;
                break;
            }
            char top_ch = pop();
            if (is_open(top_ch) != is_close(ch))
                balanced = 0;
        }
        index++;
    }
    return (balanced == 1 && is_empty() == 1);
}
int is_close(char ch)
{
    for (int i = 0; i < strlen(CLOSE); i++)
    {
        if (CLOSE[i] == ch)
            return i; //소괄호는 0, 대괄호는 1, 중괄호는 2를 반환
    }
    return -1; // 여는 괄호가 아니면 -1 반환
}
int is_open(char ch)
{
    for (int i = 0; i < strlen(OPEN); i++)
    {
        if (OPEN[i] == ch)
            return i;
        return -1;
    }
}
