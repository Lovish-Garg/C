#include <stdio.h>
#include <stdlib.h>

typedef struct que
{
    int front, rear, size;
    unsigned int capacity;
    int *arr;
}que;

que *createQue(unsigned int capacity)
{
    que *q = (que *)malloc(sizeof(que));

    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->capacity = capacity;
    q->arr = (int *)malloc(sizeof(int) * capacity);
    return q;
}

int isfull(que *q)
{
    return q->size == q->capacity - 1;
}
void engue(que *q, int data)
{
    if (isfull(q))
        return;

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;
    q->size++;
    printf("%d enqued into queue\n", data) ;
}

int isEmpty(que *q)
{
    return q->size == 0;
}

void deque(que *q)
{   
    if (isEmpty(q))
        return;
    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    printf("%d dequeued from queue\n", item);
}

int front(que *q)
{
    if (isEmpty(q))
        return -1;
    return q->arr[q->front];
}

int rear(que *q)
{
    if (isEmpty(q))
        return -1;
    return q->arr[q->rear];
}

int main(void)
{
    que *q = createQue(1000);

    engue(q, 10);
    engue(q, 20);
    engue(q, 30);
    engue(q, 40);

    deque(q);

    printf("%d is at front in queue\n", front(q));
    printf("%d is at rear in queue\n", rear(q));
    return 0;
}
