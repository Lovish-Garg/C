// This program prints the Maximum difference between two elements such that larger element appears after the smaller number
#include <stdio.h>

int get_max(int arr[], int n)
{
	if (n < 2)
		return -1;

	int max_diff = arr[1] - arr[0];
	int min_elem = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] - min_elem > max_diff)
		{
			max_diff = arr[i] - min_elem;
		}

		if (arr[i] < min_elem)
			min_elem = arr[i];
	}
	return max_diff;
}

int main(void)
{
	int n;

	printf("Input number of elements: ");
	scanf("%d", &n);

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		printf("Input data for %d element: ", i);
		scanf("%d", &arr[i]);
	}

	printf("\nOutput: %d\n", get_max(arr, n));
}