#include <stdio.h>
#include <stdlib.h>

int closestZero(int arr[], int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int mid, int l, int r);

int main(void)
{
	int n;

	printf("Input number of elements:");
	scanf("%d", &n);

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		printf("Input data for %d element: ", i + 1);
		scanf("%d", &arr[i]);
	}
	
	printf("\n%d\n", closestZero(arr, n));
	
	getchar();
}

int closestZero(int arr[], int n)
{
	merge_sort(arr, 0, n - 1);

	int l = 0, r = n - 1;
    int max_sum = arr[l] + arr[r];

	while (l < r)
	{
		int sum = arr[l] + arr[r];

		if (sum == 0)
		{
			return 0;
		}

		if (abs(max_sum) > abs(sum))
		{
		 	max_sum = sum;
 		}
		 
		if (sum < 0)
		{
		 	l++;
		}
		else
		{
		 	r--;
		}
	}
    return max_sum;
}
void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;

		merge_sort(arr, l, mid);
		merge_sort(arr, mid + 1, r);
		merge(arr, mid, l, r);
	}
}

void merge(int arr[], int mid, int l, int r)
{
	int n1 = mid - l + 1;
	int n2 = r - mid;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}

	for (int i = 0; i < n2; i++)
	{
		R[i] = arr[mid + i + 1];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		k++;
		i++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		k++;
		j++;
	}
}

