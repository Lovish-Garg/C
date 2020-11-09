#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <cstdlib>


int upper(int arr[], int num, int size);
/*
  In this function i'm storing difference of num and the I th element of array and subtracting num from Ith element.
  The smaller the difference means closer the number to the num.
  */
int lower(int arr[], int num, int size);
 /*
  In this function i'm storing difference of num and the I th element of array.
  but here i'm subtracting Ith element from num.
  The smaller the difference means closer the number to the num. 
  */
int near(int arr[], int num, int size);
/*
  In this function i'm storing difference of num and the I th element of array
  but here i'm not using AND operator as a boolean expression and I'm using abs function that returns absolute value of a number.
  The smaller the difference means closer the number to the num.
  */

int main(void)
{
  int n;

  printf("Input the size of the array: ");
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    printf("\nInput data for %d element: ", i + 1);
    scanf("%d", &arr[i]);
  }

  char line[10];

  while (getchar() != '\n');

  do 
  {
    printf("\nInput choice or write ""--help"" for help:  ");
    fgets(line, 9, stdin);
    if (strcmp("--help\n", line) == 0)
    {
      printf("\nInput ""upper"" for nearest upper or equal to  number\nInput ""lower"" for nearest lower or equal to  number\nInput ""near"" for nearest number in array");
    }
  }
  while ((strcmp("near\n", line) != 0) && (strcmp("upper\n", line) != 0 && (strcmp("lower\n", line) != 0)));

  int num;
  // for upper choice
  if (!strcmp("upper\n", line))
  {
    printf("\nInput the numbers of which you want to get nearest (bigger or equal to) from array: ");
    scanf("%d", &num);

    printf("The nearest larger or equal to of %d is %d\n", num, arr[upper(arr, num, n)]);
  }

  // for lower choice
  if (!strcmp("lower\n", line))
  {
    printf("\nInput the numbers of which you want to get nearest (smaller or equal to) from array: ");
    scanf("%d", &num);

    printf("The nearest larger or equal to of %d is %d\n", num, arr[lower(arr, num, n)]);
  }

  // for near choice
  if (!strcmp("near\n", line))
  {
    printf("\nInput the numbers of which you want to get nearest from array: ");
    scanf("%d", &num);

    printf("The nearest larger or equal to of %d is %d\n", num, arr[near(arr, num, n)]);
  }

  return 0;
}

int upper(int arr[], int num, int size)
{
  int check = INT_MAX, contain = -1;

  printf("\n");
  for (int i = 0; i < size; i++)
  {
    if(arr[i] - num < check && (arr[i] - num) >= 0)
    {
      check = arr[i] - num;
      contain = i;
    }
  }
  return contain;
}

int lower(int arr[], int num, int size)
{
  int check = INT_MAX, contain = -1;

  printf("\n");
  for (int i = 0; i < size; i++)
  {
    if(num - arr[i] < check && (num - arr[i]) >= 0)
    {
      check = num - arr[i];
      contain = i;
    }
  }
  return contain;
}

int near(int arr[], int num, int size)
{
  int check = INT_MAX, contain = -1;

  printf("\n");
  for (int i = 0; i < size; i++)
  {
    if(abs(arr[i] - num) < check)
    {

      check = abs(arr[i] - num);
      contain = i;
    }
  }
  return contain;
}
