#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sum(int n);
int main_asd(void) 
{
    
    int X;
    int total=0;

    scanf("%d",&X);

    for(int i=1;i<=X;i++)
    {
        total+=sum(i);
    }

    printf("%d\n",total);

    return 0;
}
int sum(int n)
{
    int add=0;
    for(int j=1;j<=n;j++)
    {
        add+=j;
    }

    return add;
}


