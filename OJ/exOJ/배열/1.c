#include <stdio.h>
#include <stdlib.h>
void re_arr(int *arr, int from, int to);
int main(void)
{
    int N;
    int arr[101];
    int num, a, b;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &a, &b);
        re_arr(arr, a, b);
    }

    for (int i = 0; i < N; i++)
        printf(" %d", arr[i]);

    return 0;
}
void re_arr(int *arr, int from, int to)
{
    int i = from, j = to;
    int temp;
    int gap = to - from;

    if (gap % 2 == 0)
    {
        int count = gap / 2;
        while (count--)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    else
    {
        int count = gap / 2 + 1;

        while (count--)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
}
/* 
10
3 81 9 12 0 -9 36 33 91 10
3
3 7 4 5 0 4

6
30 10 20 0 40 50
2
1 2 0 3
*/