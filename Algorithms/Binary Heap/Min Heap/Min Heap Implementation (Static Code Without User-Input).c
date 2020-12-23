// This program is for min-heap and its a bit complicated and its static code and this code doesnot have run-time ability
// There is also run-time Min Heap program. Its located in this same folder
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // capacity for min-heap
    
typedef struct min_heap
{   
    int *arr;// pointer to array for min-heap
    int capacity;
    int curr_size;
}min_heap;

/*
    funtions that we use directly from main function have definitions her but 
    other functions which are called by these functions have definitions 
    start from line 41
*/
void free_heap(min_heap *);// to free the memory used by heap
min_heap *Create_heap(int);// to create heap
int getMin(min_heap *heap);// to get the value of root element which is the smallest
void print_heap(min_heap *);// to print heap
void insert(min_heap *, int);// to insert new element
void delete(min_heap *, int);// to delete element from heap from ith place
void decreaseKey(min_heap *, int, int);// to decrease the value of a key at ith Index

int main(void)
{
    // creating a heap 
    min_heap *heap = Create_heap(MAX);

    // inserting data in heap
    insert(heap, 100);
    insert(heap, 2);
    insert(heap, 10);
    insert(heap, 3);
    insert(heap, 9);
    insert(heap, 1);
    /*
        To remove element from desire place you can change the values
        of the parameters of delete function or add new functions do some experiment
        with it.
    */
    delete(heap, 2);

    /*
        parameters (heap, index, new_value for index) . 
        At index 4 the value is 9 but after this value will be 0.
        You can comment the decreaseKey function below and then see the result.
    */
    decreaseKey(heap, 4, 0);

    printf("Root: %d\n", getMin(heap));
    printf("The heap->\n");
    print_heap(heap);

    free_heap(heap);// freeing memory is a necessary step
}

// all one line functions
int parent(int i) { return (i-1)/2; }// to get the parent node of a child node
int left_key(int i) {return i * 2 + 1; }// returns left child 
int right_key(int i) {return i * 2 + 2; }// returns right child 
int getMin(min_heap *heap){ return heap->arr[0]; }// to get the root element from heap
int isEmpty(min_heap *heap){ return (heap->curr_size == 0) ? 1 : 0; }// to check if heap is empty
int isFull(min_heap *heap){ return (heap->curr_size == heap->capacity); }// to check if heap is fulls
void swap(int *num, int *num2) { int temp = *num; *num = *num2; *num2 = temp; }// to swap

// definitions of functions called by functions which are called by main
void heapifyUp(min_heap *, int);// we will call this function when we need to insert some number in heap
min_heap *heapifyDown(min_heap *, int);// we will call this function when we need to delete some key

min_heap *Create_heap(int size)
{
    min_heap *new_heap = (min_heap *)malloc(sizeof(min_heap));

    new_heap->capacity = size;
    new_heap->arr = (int *)malloc(sizeof(int) * MAX);// allocating memory for array
    new_heap->curr_size = 0;

    return new_heap;
}

void insert(min_heap *heap, int key)
{
    if (isFull(heap))
    {   
        printf("\nOveflow\n");
        exit(0);
    }

    heapifyUp(heap, key);// as there is post increment so value will increment later
    ++heap->curr_size;
}


// We will call this function when we insert data in heap
void heapifyUp(min_heap *heap, int key)
{   
    int size = heap->curr_size;

    heap->arr[size] = key;

    // here we are fixing the property of min_heap if it is being violated
    while (size != 0 && heap->arr[parent(size)] > heap->arr[size])
    {
        swap(&heap->arr[parent(size)], &heap->arr[size]);
        size = parent(size);
    }
}

// in this function the value at the index will get decreased
void decreaseKey(min_heap *heap, int index, int new_val)
{
    heap->arr[index] = new_val % heap->arr[index];// % heap->arr[index] to ensure that the new value is smaller or equal to of previous value

    while (index != 0 && heap->arr[parent(index)] > heap->arr[index])
    {
        swap(&heap->arr[index], &heap->arr[parent(index)]);
        index = parent(index);
    }
}
// this function deletes the key at index i
void delete(min_heap *heap, int i)
{
    if (isEmpty(heap))
    {
        printf("\nUnderflow\n");
        exit(0);
    }
    
    int last_elem = heap->arr[--heap->curr_size];// here i'm pre-decrementing 
    int size = heap->curr_size;

    // updating ith element with last element in the heap
    heap->arr[i] = last_elem;

    heap = heapifyDown(heap, i);// This also worked for me with jus heapifyDown(heap, 0);    

}

// we will call this function when we need to delete some key
// This function can also work with void but as this function is recursive it needs to return heap.
min_heap *heapifyDown(min_heap *heap, int key)
{   
    int size = heap->curr_size;

    if (size <= 1)
        return heap;

    int left = left_key(key);
    int right = right_key(key);
    int smallest = key;

    // means left < curr_size && arr[left] of heap is smaller than arr[key] of heap
    // by left < size we are checking that left child is in the limits of array size or not
    if (left < size && heap->arr[left] < heap->arr[key])
        smallest = left;
    
    //similar to left but here in second compare we are comparing with the smallest
    if (right < size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != key)
    {
        // we first swap and then recursively call heapifydown till smallest != key
        // In this manner we are also correcting the number which are violating the rules of min-heap
        swap(&heap->arr[smallest], &heap->arr[key]);

        heap = heapifyDown(heap, smallest);// here's recursion
    }
    return heap;
}

// function to clear the memory allocated using malloc in this case
void free_heap(min_heap *heap)
{
    
    free(heap->arr);// first freeing array section of heap
    free(heap);// freeing the heap itself
}

// funtion to print the heap
void print_heap(min_heap *heap)
{
    for (int i = 0; i < heap->curr_size; ++i)
        printf("%d ", heap->arr[i]);
}