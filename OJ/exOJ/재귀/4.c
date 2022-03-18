#include <stdio.h>
#include <stdlib.h>
int max_value(int arr[], int n);
int main(void)
{
    int N;
    int arr[20];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    printf("%d\n", max_value(arr, N));

    return 0;
}
int max_value(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    else if (n == 2)
        return arr[0] >= arr[1] ? arr[0] : arr[1];
    else
        return arr[n - 1] >= max_value(arr, n - 1) ? arr[n - 1] : max_value(arr, n - 1);
}