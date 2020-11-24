/*
    This program will only work when there is a number occurring odd times
    else the result maynot be right
*/
#include <stdio.h>

int odd_checker(int arr[], int n);

int main(void)
{   
    int n;

    printf("Input number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("input for %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("The number occuring odd times is %d\n",odd_checker(arr, n));
}

int odd_checker(int arr[], int n)
{
        int bit = 0;
        
        for (int i = 0; i < n; i++)
        {
            bit ^= arr[i];    
        }
        
        return bit;
}        
