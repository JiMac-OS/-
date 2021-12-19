#include <stdio.h>
#include <string.h>
int main(void)
{
    int N;
    int cnt = 2;
    int index=6;
    int i = 2, j = 8;

    scanf("%d", &N);

    if (N == 1)
    {
        printf("1\n");
    }
    else
    {
        while (1)
        {
            if (i <= N && N < j) // 이런 수식을 이용한 조건문을 떠올리는 연습이 부족하다. 
            // 수 많은 문제를 풀어 기본적인 수식을 이용하는 문제를 마스터 하자.
            {
                printf("%d\n",cnt);
                break;
            }
            i+=index;
            index+=6;
            j+=index;
            cnt++;
        }
    }

    return 0;
}
