/*
    This program uses Bitwise XOR '^' operator to find the missing number 
    *To understand this program you should know the Use of Bitwise XOR     
    operator and you can also use pen and paper to understand these operations.
*/
#include <stdio.h>

int get_missing(int arr[], int n);

int main(void)
{
    int n;

    printf("Input the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input data fpr %d elment: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nThe missing number in the array is %d", get_missing(arr, n));
}

int get_missing(int arr[], int n)
{
    int x1 = 0, x2 = 0, i;
    
    for (i = 0; i < n; i++)
    {
        x1 = x1 ^ (i + 1);
        x2 = x2 ^ arr[i];
    }

    x1 ^= (i + 1);

    return x1 ^ x2;
}
