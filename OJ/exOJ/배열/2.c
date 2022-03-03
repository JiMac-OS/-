#include <stdio.h>
int switch_location(int *arr, int a, int b)
{
    int temp = arr[b];
    arr[b] = a;
    return temp;
}
int main(void)
{
    int N, len, info;
    int X[100];
    int first;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &X[i]);

    scanf("%d", &len);
    scanf("%d", &first);
    for (int i = 0; i < len - 1; i++)
    {
        scanf("%d", &info);
    }
}