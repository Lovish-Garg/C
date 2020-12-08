#include <stdio.h>

void print_arr(int [], int);
void quicksort(int [], int, int);

int main(void)
{
	int t;

	printf("Testcases: ");
	scanf("%d", &t);

	while (t--)
	{
		int n;

		printf("Elements: ");
		scanf("%d", &n);

		int arr[n];

		printf("\nInput data in array->\n");
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		printf("\nBefore Sorting->\n");
		print_arr(arr, n);
		quicksort(arr, 0, n - 1);
		printf("After Sorting->\n");
		print_arr(arr, n);
	}
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
int partition(int arr[], int l, int r)
{	
	int pivot = arr[r];
	int i = l - 1;

	for (int j = l; j < r; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[r]);
	return i + 1;
}

void quicksort(int arr[], int l, int r)
{
	if (l < r)
	{
		int pi = partition(arr, l, r);

		quicksort(arr, l, pi - 1);
		quicksort(arr, pi + 1, r);
	}
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n\n");
}
