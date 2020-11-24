#include <stdio.h>
#include <stdlib.h>

// structure for nodes in the Queue
typedef struct node
{
    int data;// It will keep data
    struct node *link;// It will keep the address of next node
}node;

typedef struct Queue// This will keep the record of front and rear node in Queue
{
    node *front, *rear;// pointers to store the front and rear of Queue
}que;

que *create_que()// Creates the structure in which front and rear are stored
{
    que *q = (que *)malloc(sizeof(que));
    q->front = NULL;
    q->rear = NULL;

    return q;
}
node *create_node(int data)// creates nodes and assign them value
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->link = NULL;

    return new_node;
}

// This function calls a function to create node and this functions then push that node into queue
void enque(que *q, int data)
{
    node *new_node = create_node(data);

    if (q->front == NULL)
    {
        q->front = new_node;
        q->rear = new_node;
        printf("%d has been enqueued in the queue\n", data);
        return;
    }

    q->rear->link = new_node;
    q->rear = new_node;
    printf("%d has been enqueued in the queue\n", data);
}

int isEmpty(que *q)
{
    return q->front == NULL;
}
void deque(que *q)
{
    if (isEmpty(q))
        return;

    int data = q->front->data;
    
    node *temp = q->front;
    q->front = q->front->link;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    printf("%d has been dequeued from the queue\n", data);
}

// Well there is not much need of front and rear functions but it is better to use functions
int front(que *q)
{
    return q->front->data;
}

int rear(que *q)
{
    return q->rear->data;
}

void free_(que *q)
{   
    node *temp = q->front;

    while (temp)
    {
        q->front = q->front->link;
        free(temp);
        temp = q->front;
    }
}

int main(void)
{
    que *q = create_que();
    enque(q, 10); 
    enque(q, 20); 
    deque(q); 
    deque(q); 
    enque(q, 30); 
    enque(q, 40); 
    enque(q, 50); 
    deque(q); 
    printf("Queue Front : %d \n", front(q)); // here we can replace front function by "  q->front->data  "
    printf("Queue Rear : %d", rear(q)); // here we can replace rear function by "  q->rear->data  "
    full_que(q->front);
    free_(q);
}
