#include <stdio.h>
void ABC(int arr[], int k);
int main(void)
{

    /*  선택정렬 (가장 작은 것을 선택해서 제일 앞으로 보내는 방법)
    int arr[10];
    int i, j, temp, index, min;
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < 10; i++)
    {
        min = 9999;
        for (j = i; j < 10; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    } */

    /*  버블 정렬 (옆에 있는 값과 비교해서 더 작은 값을 앞으로 보내는 방법)
    int arr[10];
    int i, j, temp;
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    } */

    /*  삽입정렬 
    int arr[10];
    int i, j, temp;
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < 9; i++)
    {
        j = i;
        while (arr[j] > arr[j + 1] && j >= 0)
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            j--;
        }
    }
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]); */

    int arr[10];
    int i;
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < 9; i++)
        ABC(arr, i);

    for (i = 0; i < 10; i++)
        printf(" %d", arr[i]);

    printf("\n");

    return 0;
}
void ABC(int arr[], int k)
{
    //배열의 k 번째 정수부터 마지막 정수중 가장 큰 정수를 찾고, 이를 k번째 위치의 정수와 교환한다.
    int j, temp;
    for (j = 0; j < 9 - k; j++)
    {
        if (arr[j] < arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}