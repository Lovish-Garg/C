#include <stdio.h>
#include <stdlib.h>

// structure required for stack using lists
typedef struct que
{
    int data;
    struct que *link;
}Stack;

Stack *create_node(int data)
{
    Stack *new_node = (Stack *)malloc(sizeof(Stack));   
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void push(Stack **root, int value)// pointer to pointer 
{
    Stack *new_node = create_node(value);

    new_node->link = *root;
    *root = new_node;
    printf("%d pushed to stack\n", value);
}

int isEmpty(Stack *root)
{
    return !root;
}

void pop(Stack **root)
{
    if (isEmpty(*root))
        return;

    Stack *temp = *root;

    *root = (*root)->link;
    printf("%d popped from stack\n", temp->data);

    free(temp);
}

int peek(Stack *root)
{
    return root->data;
}

int main(void)
{
    Stack *stack = NULL;

// here we could also send the stack and return the position of stack from function and assign it to the stack again
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    
    pop(&stack);
    printf("%d is at top in stack\n", peek(stack));

    Stack *temp = stack;
    
    while (temp)
    {
        stack = stack->link;
        free(temp);
        temp = stack;
    }

    getchar();
}
