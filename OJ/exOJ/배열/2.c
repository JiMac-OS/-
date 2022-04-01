#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int N, arr[100];
    int len, prev, save, infor, first;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &len);
    scanf("%d", &first);
    prev = arr[first];
    for (int i = 0; i < len - 1; i++)
    {
        scanf("%d", &infor);
        save = arr[infor];
        arr[infor] = prev;
        prev = save;
    }
    for (int i = 0; i < N; i++)
        printf(" %d", arr[i]);
    printf("\n");

    return 0;
}

/* 
10
3 81 9 12 0 -9 36 33 91 10
5
3 8 0 9 3
*/