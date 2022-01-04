#include <stdio.h>
int main(void)
{
    int T,i,j,k,m;
    int n;
    int arr[20001]={0,};
    arr[1]= 1; //  소수는 0 소수가 아니면 1

    scanf("%d",&T);

    for(i=0;i<T;i++)
    {
        scanf("%d",&n);

        for(j=2;j<=n;j++)
        {
            for(k=2;j*k<=n;k++)
            {
                arr[j*k]=1;
            }
        }
        for(m=n/2;m>0;m--)  // 이 for문의 아이디어 확실히 공부하기.
        {
            if(arr[m]==0&&arr[n-m]==0)
            {
                printf("%d %d\n",m,n-m);
                break;
            }
        }

    }
    return 0;
}