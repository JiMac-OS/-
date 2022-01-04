#include <stdio.h>
int main(void)
{

    int arr[3];
    int i, j, temp, min, index;

    while (1)
    {
        int sum = 0;
        for (i = 0; i < 3; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        if (sum == 0)
            break;
        /*  for (i = 0; i < 3; i++)  //선택정렬
        {
            min = 30001;
            for (j = i; j < 3; j++)
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

        for (i = 0; i < 3; i++)  //버블 정렬
        {
            for (j = 0; j < 3 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        if ((arr[0] * arr[0]) + (arr[1] * arr[1]) == arr[2] * arr[2])
            printf("right\n");
        else
            printf("wrong\n");
    }

    return 0;
}