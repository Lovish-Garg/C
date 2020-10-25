#include <stdio.h>
#include <string.h>


int get_max(int arr[], int size);
void counting_sort(int arr[], int max, int size);

int main(void)
{
	int n;

	printf("\nInput number of elements in array: ");
	scanf("%d", &n);

	int arr[n];

  // taking input for array
	for (int i = 0;i < n; i++)
	{
		printf("Input data for %d element: ", i + 1);
		scanf("%d", &arr[i]);
	}

  // assigning the max value of array in a variable
	int max = get_max(arr, n);

	counting_sort(arr, max, n);

	return 0;
}

// function to get the largest element of the array
int get_max(int arr[], int size)
{
	int max = arr[0];

	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

// counting_sort the main function of this program
void counting_sort(int arr[], int max, int size)
{
	int sorted_arr[max + 1]; // here i'm making an array of max + 1 elements so there is also place for max number Eg. max = 12 then this will create array of 0 - 11 because of 0 based indexing. 

	memset(sorted_arr, 0, sizeof(sorted_arr));

	for (int i = 0; i < size; ++i)
	{	
		++sorted_arr[arr[i]];
	}

	printf("After sorting -> ");

	for (int i = 0; i <= max; i++)
	{
		for (int j = 0; j < sorted_arr[i]; j++)
		{
			printf("%d ", i);
		}
	}
}
