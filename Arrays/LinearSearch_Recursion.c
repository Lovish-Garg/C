#include <stdio.h>

int linear_search(int [], int, int, int);

int main(void)
{
    int n;

    printf("Input number of elements in array: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input data for %d element: ", i);
        scanf("%d", &arr[i]);
    }

    int num;

    printf("\nInput number to search through recursion: ");
    scanf("%d", &num);

    printf("The number is at %d index\n", linear_search(arr, 0, n - 1, num));
}

int linear_search(int arr[], int start, int end, int num)
{
    if (start > end)// means array doesnot exist or we havenot find the number
        return -1;

    if (arr[start] == num)
        return start;

    if (arr[end] == num)
        return end;

    return linear_search(arr, start + 1, end, num);
}
