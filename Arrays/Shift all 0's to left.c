#include <stdio.h>

void shift_zeros(int *ptr, int n);
void print_arr(int arr[], int size);

int main(void)
{ 
  int n;

  printf("Input the size of the array: ");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("Input data for %d element: ", i + 1);
    scanf("%d", &arr[i]);
  }

  shift_zeros(arr, n);
  printf("\nAfter shifting 0's in array ->");
  print_arr(arr, n);

}

void shift_zeros(int *ptr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <n; j++)
    {
      if (ptr[j] == 0)
      {
        int k = j;
        while (k < n - 1)
        {
          ptr[k] = ptr[k + 1];
          k++;
        }
        ptr[k] = 0;
      }
    }
  }
}

void print_arr(int arr[], int size)
{
  printf("\n");
  for (int i = 0; i < size; i++)
  {
    printf("At %d = %d\n", i + 1, arr[i]);
  }
}
