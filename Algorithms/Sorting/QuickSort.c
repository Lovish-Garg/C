#include <stdio.h>

void print_arr(int [], int);
void quicksort(int [], int, int);

int main(void)
{
	int t;

	printf("Testcases: ");
	scanf("%d", &t);

	while(t--)
	{
		int n;

		printf("Elements: ");
		scanf("%d", &n);

		int arr[n];

		printf("\nInput data in elements->\n");
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		printf("\nArray before sorting->\n");
		print_arr(arr, n);// displaying array before sorting

		quicksort(arr, 0, n - 1);// calling qquicksort to sort the fucntion

		printf("\n\nArray after sorting->\n");
		print_arr(arr, n);// displaying array after sorting

		printf("\n\n");
	}

	getc(stdin);
	return 0;
}

// swaps the number 
void swap(int *num, int *num2)
{
	int temp = *num;
	*num = *num2;
	*num2 = temp;
}

// it swap and bring all numbers smaller than pivot to before of the pivot
int partition(int arr[], int l, int r)
{
	int i = l;
	int pivot = arr[r];

	for (int j = l; j < r; j++)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[j], &arr[i++]);
		}
	}

	swap(&arr[i], &arr[r]);
	return i;
}

void quicksort(int arr[], int l, int r)
{
	if (l < r)
	{
		int index  = partition(arr, l, r);

		quicksort(arr, l, index - 1);
		quicksort(arr, index, r);
	}
}

void print_arr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
