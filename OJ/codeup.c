#include <stdio.h>
int main_a(void)
{ 
    int arr[11][11]={0};
    int x=2,y=2;

    for(int i=1;i<11;i++)
    {
        for(int j=1;j<11;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }


    while(1)
    {
        if(arr[x][y]==0)
        {
            arr[x][y]=9;
            y++;
        }
        else if(arr[x][y]==1)
        {
            y--;
            x++;
        }
        else if(arr[x][y]==2)
        {
            arr[x][y]=9;
            break;
        }
        else if(arr[x+1][y]==1&&arr[x][y+1]==1)
        {
            arr[x][y]=9;
            break;
        }
    }
    for(int i=1;i<11;i++)
    {
        for(int j=1;j<11;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    
    return 0;

}