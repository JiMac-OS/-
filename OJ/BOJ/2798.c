#include <stdio.h>
#define cards 100
int main(void)
{
    int N, M;
    int card[cards];
    int sum, max = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &card[i]);

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                sum = card[i] + card[j] + card[k];
                if (sum > max && sum <= M)
                    max = sum;
            }
        }
    }
    printf("%d\n", max);

    return 0;
}