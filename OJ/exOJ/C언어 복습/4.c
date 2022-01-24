#include <stdio.h>
#include <string.h>
void shift(char *arr);
int main(void)
{
    char arr[101];
    char temp;
    int i, j;
    scanf("%s", arr);
    int len = strlen(arr);
    // strlen은 NULL 값 포함 x
    printf("%s\n", arr);
    for (i = 0; i < len - 1; i++)
    {
        shift(arr);
        printf("%s\n", arr);
    }

    return 0;
}
void shift(char *arr)
{
    char *p, temp = *arr;
    int len = strlen(arr);

    for (p = arr; p < arr + len - 1; p++)
    {
        *p = *(p + 1);
    }
    *p = temp;
}