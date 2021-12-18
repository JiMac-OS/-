#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define CAPACITY 100
#define BUFFER_SIZE 20

// strcpy : 문자열 복사
// strlen : 문자열의 길이
// strcat : 문자열 합치기
// strcmp : 문자열 비교

void add();
void find();
void status();
void remover();
void load();
void save();
int search(char *name);

char *names[CAPACITY];
char *numbers[CAPACITY];
int n = 0; // number of people

int main(void)
{
    char buffer[BUFFER_SIZE];
    while (1)
    {
        printf("$ ");
        scanf("%s", buffer);

        if (strcmp(buffer, "read") == 0)
            load();
        else if (strcmp(buffer, "add") == 0)
            add();
        else if (strcmp(buffer, "find") == 0)
            find();
        else if (strcmp(buffer, "status") == 0)
            status();
        else if (strcmp(buffer, "delete") == 0)
            remover();
        else if (strcmp(buffer, "save") == 0)
            save();
        else if (strcmp(buffer, "exit") == 0)
            break;
    }
    return 0;
}

void load()
{
    char fileName[BUFFER_SIZE];
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL)
    {
         printf("Open failed. \n");
        return;
    }

    while ((fscanf(fp, "%s", buf1)) != EOF)
    {
        fscanf(fp, "%s", buf2);
        names[n] = strdup(buf1);
        numbers[n] = strdup(buf2);
        n++;
    }
    fclose(fp); //볼일이 끝난 파일은 반드시 닫아 주어야 한다.
}
void save()
{
    int i;
    char tmp[BUFFER_SIZE];
    char fileName[BUFFER_SIZE];

    scanf("%s", tmp);
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "w"); // 쓰기 위해서는 기존에 파일 없어도 가능.
    // 자동으로 만들어 준다. 다만 읽을 때는 있어야 한다.
    if (fp == NULL)
    {
        printf("Open failed.\n");
        return;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}
void add()
{
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);

    int i = n - 1;
    while (i >= 0 && strcmp(names[i], buf1) > 0)
    {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = strdup(buf1);
    numbers[i + 1] = strdup(buf2);
    n++;
    printf("%s was added successfully.\n", buf1);
}
void find()
{
    char buf[BUFFER_SIZE];
    scanf("%s", buf);
    int index = search(buf);
    if (index == -1)
        printf("No person named '%s' exists.\n", buf);
    else
        printf("%s\n", numbers[index]);
}
void status()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s %s\n", names[i], numbers[i]);
    }
    printf("Total %d person. \n", n);
}
void remover()
{ // 맨 마지막 사람을 삭제한 위치에 옮긴다.
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int index = search(buf); // returns -1 if not exists
    if (index == -1)
    {
        printf("No person named '%s' exists. \n", buf);
        return;
    }
    int j = index;
    for (; j < n - 1; j++)
    {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }
    n--;
    printf("No person named '%s' exists.\n", buf);
}
int search(char *name)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(name, names[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}
