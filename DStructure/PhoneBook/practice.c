#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 20 //단어 하나의 길이가 20을 넘지 않는다.
int read_line_with_compression(char compressed[],int limit);
int main_asd()
{
    char line[80];
    while(1)
    {
        printf("$ ");
        int length = read_line_with_compression(line,80);
        printf("s:%d\n", line, length);
    }    


    return 0;
}

int read_line_with_compression(char compressed[],int limit)
{
    int ch, i = 0;
    while((ch=getchar())!= '\n')
    {
        if(i<limit-1 && (!isspace(ch)) || i > 0 && !isspace(compressed[i-1]))
        {
            compressed[i++] = ch;
        }
    }
    if(i>0 && isspace(compressed[i-1]))
    {
        i--;
    }
    compressed[i]='\0';

    return i;
}