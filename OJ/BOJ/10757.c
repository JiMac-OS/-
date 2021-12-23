#include <stdio.h>
#include <string.h>
void reverse(char arr[]);
int main(void)
{
    char arr1[10002] = {
        0,
    };
    char arr2[10002] = {
        0,
    };
    char total[10003] = {
        0,
    };
    int carry = 0;

    scanf("%s %s", arr1, arr2);

    reverse(arr1);
    reverse(arr2);

    int len = strlen(arr1) > strlen(arr2) ? strlen(arr1) : strlen(arr2);

    for (int i = 0; i < len; i++)
    {
        int sum = arr1[i] - '0' + arr2[i] - '0' + carry;
        if (sum < 0)
        {
            sum += '0';
        }
        if (sum > 9)
        {
            carry = 1;
        }
        else
            carry = 0;
        total[i] = sum % 10 + '0';
    }

    if (carry == 1)
    {
        total[len] = '1';
    }
    reverse(total);
    printf("%s", total);
    return 0;
}
void reverse(char arr[])
{
    int len = strlen(arr);
    char temp;

    for (int i = 0; i < len / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}
