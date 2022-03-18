#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int count(char *str, char c, int cnt);
int main(void)
{
    char *arr;
    char check;
    arr = (char *)malloc(sizeof(char) * 101);
    scanf("%s", arr);
    getchar();
    scanf("%c", &check);
    printf("%d\n", count(arr, check, 0));
    free(arr);
    return 0;
}
int count(char *str, char c, int cnt)
{
    if (*str == 0)
        return cnt;
    else if (*str == c)
        return count(str + 1, c, cnt + 1);
    else
        return count(str + 1, c, cnt);
}