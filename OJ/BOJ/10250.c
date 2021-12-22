#include <stdio.h>
int main(void)
{
    int T;
    int H,W,N;
    int answer;
    int room;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        room=101;
        scanf("%d %d %d",&H,&W,&N);
        if(N==1)
        {
            printf("101\n");
            continue;
        }
        for(int j=1;j<=W;j++)
        {
            for(int k=0;k<H;k++,N--)
            {
                answer=room;
                if(N==0)
                {
                    printf("%d\n",answer);
                    break;
                }
                room+=100;

            }
            if(N==0)break;
            room=101+j;
        }
    }
    return 0;
}