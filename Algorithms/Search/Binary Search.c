#include <stdio.h>

int binary_search(int arr[], int start, int end, int num);
void sort_arr(int *ptr, int n);

int main(void)
{
	int n;

	printf("\nInput the size of the array: ");
	scanf("%d", &n);

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		printf("Input data for %d elemnet: ", i);
		scanf("%d", &arr[i]);
	}

	sort_arr(arr, n); // here I'm using selection-sort alogorithm

	printf("After sorting-> ");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	int num;

	printf("\nInput the number to be searched: ");
	scanf("%d", &num);

	int index = binary_search(arr, 0, n - 1, num);

	if (index == -1) // number ddoesnot exist
	{
		printf("%d doesnot exist in the array", num);
	}
	else
	{
		printf("%d is located at %d index of the array", num, index);
	}
}

/*
	Here j = i means I'm assigning the smallest number available in 
	the array to min variable and the index of that number in  index
	variable then swapping theses number . Here j = i is important 
	thing.
*/
void sort_arr(int *ptr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = ptr[i], index = i;
		for (int j = i; j  < n; j++)
		{
			if (min > ptr[j])
			{
				min = ptr[j];
				index = j;
			}
		}
		ptr[index] = ptr[i];
		ptr[i] = min;
	}
}

/*
	*Here mid = (start + end) / 2 
	*if arr[mid] == number I'm searching, then return mid as index
	*if arr[mid] > number , then end = mid - 1
	*else means arr[mid] < number then start = mid + 1

	example here's an array:
	numbers: 0 | 9 | 10 | 31 | 35 |
	indexes: 0 | 1 |  2 |  3 | 4  |
	
	here i'm searching 31
	
	first mid = start which is 0 + end which is 4 / 2 so mid = 2

	arr[mid] != num;
	arr[mid] !> num;
	
	arr[mid] < num 
	so left = mid +1

	so (3 + 4) / 2 = 3

	so mid = 3 
	arr[mid] == num
	so I will return the mid as index
*/
int binary_search(int arr[], int start, int end, int num)
{
	while (start <= end)
	{
		int mid = (start +  end) / 2;

		if (arr[mid] == num)
			return mid;
		
		else if(arr[mid] > num)
			end = mid - 1;
		
		else
			start = mid + 1;
	}
	return -1;
}
