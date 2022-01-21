#include <stdio.h>
void swap(int *p, int *q);
int main(void)
{
    int N, a, b;
    int arr[50];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &a, &b);

    swap(&arr[a], &arr[b]);

    for (int i = 0; i < N; i++)
        printf(" %d", arr[i]);

    return 0;
}
void swap(int *p, int *q)
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;
}