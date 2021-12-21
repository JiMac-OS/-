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
        for(int j=1;j<=W;j++)
        {
            for(int k=0;k<H;k++,N--)
            {
                if(N==0)
                {
                    printf("%d\n",answer);
                    break;
                }
                answer=room;
                room+=100;

            }
            if(N==0)break;
            room=101+j;
        }
    }
    return 0;
}