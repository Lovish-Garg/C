  
#include <stdio.h>

void left_rotate(int arr[], int, int);
int gcd_count(int x, int y);
void printArray(int arr[], int n) ;

int main(void)
{
    int n, d;

    printf("Input number of elements: ");

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Input data for %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nInput n numbers  to shift the array: ");
    scanf("%d", &d);

    left_rotate(arr, d, n);

    printArray(arr, n);
}

void left_rotate(int arr[], int d, int n)
{
    d = d % n;

    int gcd = gcd_count(d, n);
    for (int i = 0; i < gcd; i++) { 
     /* move i-th values of blocks*/
        int temp = arr[i]; 
        int j = i; 
        while (1) { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
            if (k == i) 
                break; 
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    } 

}

int gcd_count(int a, int b)
{
    int temp;

    while (b)
    {
        temp = a;
        a = b; 
        b = temp % b;
    }
    return a;
}

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
} 
