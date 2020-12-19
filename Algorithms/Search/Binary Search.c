#include <stdio.h>

void merge_sort(int arr[], int, int);
void merge(int arr[], int, int l, int r);
int binary_search(int arr[], int start, int end, int num);

int main(void)
{
    int t;

    printf("Testcases: ");
    scanf("%d", &t);

    while (t--)
    {
        int n;

        printf("\nNumber of Elements: ");
        scanf("%d", &n);

        int arr[n];

        printf("\nInput data in array->\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        merge_sort(arr, 0, n - 1); // here I'm using merge-sort alogorithm

        printf("\nAfter sorting-> ");

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }

        int num;

        printf("\n\nInput the number to be searched: ");
        scanf("%d", &num);

        int index = binary_search(arr, 0, n - 1, num);

        if (index == -1) // number doesnot exist
        {
            printf("\n%d not found", num);
        }
        else
        {
            printf("\n%d is located at %d index", num, index);
        }

        printf("\n");
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        merge_sort(arr, l, mid);// divide the first half
        merge_sort(arr, mid + 1, r);// divide the second half 
        merge(arr, mid,  l, r);// merge the two halfs
    }
}

void merge(int arr[], int mid, int l, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + j + 1];

    int i = 0; 
    int j = 0;
    int k = l;

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
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
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
