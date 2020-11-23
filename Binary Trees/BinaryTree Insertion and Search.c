#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int data;
    struct tree *left, *right;
}tree;

tree *create_node(int data)
{
    tree *node = (tree *)malloc(sizeof(tree));

    node->data = data;
    node->left = node->right = NULL;

    return node;
}

void print_tree(tree *root)
{
    
    if (root == NULL)
        return;
    printf("%d ", root->data);
    print_tree(root->left);
    print_tree(root->right);
}

void free_(tree *root)
{
    if (root == NULL)
        return;
    free_(root->left);
    free_(root->right);
    tree *temp = root;
    free(temp);
}
int main(void)
{
    tree *root = create_node(1);  
    /*
                1
               / \
              2   3
             /   / \
            4   5   6
    */
    root->left = create_node(2);
    root->right = create_node(3);

    root->left->left = create_node(4);
    root->right->left = create_node(5);
    root->right->right = create_node(6);

    print_tree(root);
    free_(root);// to free the memory 
}
