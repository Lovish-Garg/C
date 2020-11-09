// user needs to provide array sorted 
#include <stdio.h>

int merge_sort_median(int arr1[], int arr2[], int n1, int n2);
int get_median(int arr[], int n);

int main(void)
{
    int n1, n2;

    printf("Input number of elements for first array: ");
    scanf("%d", &n1);

    int arr[n1];

    for (int i = 0; i < n1; i++)
    {
        printf("Input data for %d element: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nInput number of elements for second array: ");
    scanf("%d", &n2);

    int arr2[n2];

    for (int i = 0; i < n2; i++)
    {
        printf("Input data for %d element: ", i);
        scanf("%d", &arr2[i]);
    }
    
    printf("\nThe median is %d\n", merge_sort_median(arr, arr2, n1, n2));
    return 0;
}

int merge_sort_median(int arr1[], int arr2[], int n1, int n2)
{
    int arr[n1 + n2];

    int i = 0, j = 0;   

    for (int k = 0, sum = n1 + n2; k < sum; k++)
    {
        if (i < sum && arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
    }
    int median = get_median(arr, n1 + n2);
    return median;
}

int get_median(int arr[], int n)
{
    if (n == 0)
    {
        return -1;
    }
    if (n == 1)
    {
        return arr[0] / 2;
    }

    if (n == 2)
    {
        return (arr[0] + arr[1]) / 2;
    }

    if (n % 2 == 0)
    {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }
    else
        return arr[n / 2] / 2;   
}
