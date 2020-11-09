#include <stdio.h> 

int find_pivot(int arr[], int left, int right);

int main(void)
{
		int n;

		printf("\nInput number of elements in array: ");
		scanf("%d", &n);

		int arr[n];

		for (int i = 0;i < n; i++)
		{
			printf("Input data for %d element: ", i);
			scanf("%d", &arr[i]);
		}

		int check = find_pivot(arr, 0, n - 1);

		if (check == -1)
  		{
  			printf("\nArray is not right");
  		}
	  	else
	  	{
	  		printf("\nPivot element in the array is %d at %d index", arr[check], check);
	  	}

  		return 0;
}

int find_pivot(int arr[], int left, int right)
{
	if (arr[left] <= arr[right])
	{
		return -1;
	}
	while (left <= right)//  5, 6, 7, 8, 9, 10, 1, 2, 3 
	{
		int middle =  (left + right) / 2;

		if (arr[middle] > arr[middle + 1])
		{
			return middle + 1;
		}
		else if (arr[left] <= arr[middle])
		{
			left = middle + 1;
		}												
		else
		{
			right = middle - 1;
		}
	}
	return -1;
}
