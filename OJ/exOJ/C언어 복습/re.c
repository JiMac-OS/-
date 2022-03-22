#include <stdio.h>
#include <stdlib.h>
void change(int *arr, int from, int to);
int main(void)
{
    int *arr, *p;
    int N, cnt, from, to;
    arr = (int *)malloc(sizeof(int) * 101);
    scanf("%d", &N);
    for (p = arr; p < arr + N; p++)
        scanf("%d", p);

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++)
    {
        scanf("%d %d", &from, &to);
        change(arr, from, to);
    }

    for (p = arr; p < arr + N; p++)
        printf(" %d", *p);
    printf("\n");
    free(arr);
    return 0;
}
void change(int *arr, int from, int to)
{
    int i = from, j = to, tmp;
    int gap = to - from;
    if (gap % 2 == 0)
    {
        int count = gap / 2;
        while (count--)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    else
    {
        int count = gap / 2 + 1;
        while (count--)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
}