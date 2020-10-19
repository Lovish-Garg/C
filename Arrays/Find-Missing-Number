#include <stdio.h>

void selection_sort(int *ptr, int size);

int main(void)
{

  int n;

  printf("Input the size of the array: ");
  scanf("%d", &n);

  int arr[n], min , max;

  printf("\nInput data for %d element: ", 1);
  scanf("%d", &arr[0]);

  min = arr[0] , max = arr[0];

  for (int i = 1; i < n; i++)
  { 
    printf("\nInput data for %d element: ", i + 1);
    scanf("%d", &arr[i]);

    if (min > arr[i])
    {
      min = arr[i]; // choosing smallest number from the array
    }
    if (max < arr[i])
    {
      max = arr[i]; // choosing maximum number from the array
    }
  }

  selection_sort(arr, n); // using sorting function and it gives the address of the first index of the array

  printf("\n\nMissing numbers in the array are -> ");

  for (int i = 1; i < n; i++)
  {
    if (arr[i] != arr[i - 1] + 1)
    {
      int num = arr[i - 1];
      while (num != arr[i] && num != arr[i] - 1)
      printf("%d ", num += 1);
      /* 
      process for the choosing of elements those  were missing.
      */
    }
  }
  return 0;
}

void selection_sort(int *ptr, int size)
{
  int swaps = 0;

  for (int i = 0; i < size; i++)
  {
    for (int j = i; j < size; j++)
    {
      if (ptr[i] > ptr[j])
      {
    int temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
        swaps++;
      }
    }
    
  }
}
