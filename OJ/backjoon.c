#include <stdio.h>
#include <string.h>
int main(void)
{
    int A, B, C;
    int x;
    int i;


    scanf("%d %d %d", &A, &B, &C);

    if(C<=B)printf("-1\n");
    else printf("%d\n",A/(C-B)+1);

    return 0;

}