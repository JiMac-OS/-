#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 20 //단어 하나의 길이가 100을 넘지 않는다.

// strcpy : 문자열 복사
// strlen : 문자열의 길이
// strcat : 문자열 합치기
// strcmp : 문자열 비교
int read_line(char str[],int n);

int main_Asd(void)
{
   /*  char* words[100]; 
    int n = 0;
    char buffer[BUFFER_SIZE];


    while(n<4 && scanf("%s",buffer) != EOF) //배열의 이름이 실제 그 주소를 저장하고 있다.
    {
        // words[n] = buffer;  // 각 칸에 buffer의 주소값만 저장된다.  잘못된 방법
        // strcpy(words[n],buffer); //  strcpy(str2,str1); 
        words[n] = strdup(buffer);


        n++;   
    } 
    
    for(int i=0;i<4; i++)
    {
        printf("%s\n",words[i]);
    }
 */

    char buffer[BUFFER_SIZE];

    while(1)
{
    printf("$ ");
    int len = read_line(buffer,BUFFER_SIZE);
    printf("%s : %d\n",buffer,len);

}

    return 0;
}


int read_line(char str[],int n)
{
    int ch, i = 0;
    while((ch=getchar())!='\n')  // getchar의 return 타입은 int 형 이다.
    {
        if(i<n)
        {
            str[i++]= ch;
        }
    }
    str[i] = '\0';

    return i;
}