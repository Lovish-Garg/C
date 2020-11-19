#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
}node;

node *create_node(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *root, int data)
{
    if (root == NULL)
        return create_node(data);

    if (data < root->data)
        root->left = insert(root->left, data);

    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct node* root) 
{ 
    if (root) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 

void free_(node *root)
{
    if (root)
    {
        free_(root->left);
        free_(root->right);
        free(root);
    }
}

node *delete(node *root, int num)
{
    if (root == NULL)
    {
        printf("%d not found\n", num);
    }

    if (root->data == num)
    {
            printf("%d has been removed from tree\n", root->data);
            free_(root);
            return NULL;
    }

    else if (num < root->data)
        root->left = delete(root->left, num);

    else if(num > root->data)
        root->right = delete(root->right, num);
    return root;
}
int main(void)
{

    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    node *root = NULL;

    root = insert(root, 50);
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    inorder(root); 

    int num;
    printf("\nInput the number you want to delete: ");
    scanf("%d", &num);

    root = delete(root, num);
    inorder(root);     
    free_(root);
}
