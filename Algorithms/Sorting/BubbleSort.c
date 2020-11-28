#include <stdio.h>

void bubble_sort(int [], int);
void print_arr(int [], int);
int main(void)
{
    int t;

    printf("Testcases: ");
    scanf("%d", &t);

    while (t--)
    {
        int n;

        printf("Input elements: ");    
        scanf("%d", &n);

        int arr[n];

        printf("\nInput data in array->\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        bubble_sort(arr, n);
        printf("\nAfter sorting->\n");
        print_arr(arr, n);
    }
    getchar();   
    getchar();
    return 0;
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)// with each i++ last elements are going to be settle 
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}
