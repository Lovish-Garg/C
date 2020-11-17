#include <stdio.h>
#include <stdlib.h>

// structure required for stack
typedef struct que
{
    int top;// this stores the index of number i.e. on top of stack
    unsigned int capacity;// capacity of arr 
    int *arr;// pointer to dynamically allocated memeory in which numbers are stored using stack
}Stack;

Stack *creatStack(unsigned int data)// Stack creater
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    stack->capacity = data;
    stack->top = -1;
    stack->arr = (int *)malloc(data * sizeof(int));

    return stack;
}


int isEmpty(Stack *stack)// Check is Stack is Empty
{
    return stack->top == -1;
}

int isfull(Stack *stack)// Check is Stack is Full
{
    return stack->top == stack->capacity - 1;
}


void push(Stack *stack, int value)// Push the elements in stack
{
    if (isfull(stack))
        return;

    stack->arr[++stack->top] = value;// It means goto arr and then increment top and then assign the value
    printf("%d enstackd to stack\n", value); 
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;

    
    return stack->arr[stack->top--];// It means goto array and then return top value , then decrement top
}

int peek(Stack *q)// To see the topmost element
{
    return q->arr[q->top];
}

int main(void)
{
    Stack *stack = creatStack(1000);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    
    printf("%d destacked from stack\n\n", pop(stack));
    printf("top item is %d\n", peek(stack)); 
    free(stack->arr);
    free(stack);
    getchar();
}
