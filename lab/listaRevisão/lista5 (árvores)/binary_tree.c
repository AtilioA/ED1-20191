#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

BinaryTree *create_BinaryTree()
{
    BinaryTree *new = (BinaryTree *)malloc(sizeof(BinaryTree));

    (*new) = NULL;

    return new;
}

int insert_BinaryTree(BinaryTree *root, int data)
{
    if (root != NULL)
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->left = NULL;
        new->right = NULL;
        new->data = data;

        if ((*root) == NULL)
        {
            (*root) = new;
            return 1;
        }

        Node *aux = (*root);
        while (aux->left != NULL || aux->right != NULL)
        {
            if (data < aux->data)
            {
                if ((*root)->left == NULL)
                {
                    break;
                }
                else
                {
                    aux = aux->left;
                }
            }
            else if (data > aux->data)
            {
                if ((*root)->right == NULL)
                {
                    break;
                }
                else
                {
                    aux = aux->right;
                }
            }
            else
            {
                printf("Data is already present in the binary tree.\n");
                return 0;
            }
        }

        if (data < aux->data)
        {
            aux->left = new;
        }
        else if (data > aux->data)
        {
            aux->right = new;
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

void print_pre_order_BinaryTree(BinaryTree *root)
{
    if (root != NULL)
    {
        printf("%i\n", (*root)->data);

        if ((*root)->left != NULL)
        {
            print_pre_order_BinaryTree(&((*root)->left));
        }

        if ((*root)->right != NULL)
        {
            print_pre_order_BinaryTree(&((*root)->right));
        }
    }
}

void print_in_order_BinaryTree(BinaryTree *root)
{
    if (root != NULL)
    {
        if ((*root)->left != NULL)
        {
            print_in_order_BinaryTree(&((*root)->left));
        }

        printf("%i\n", (*root)->data);

        if ((*root)->right != NULL)
        {
            print_in_order_BinaryTree(&((*root)->right));
        }
    }
}

void print_post_order_BinaryTree(BinaryTree *root)
{
    if (root != NULL)
    {
        if ((*root)->left != NULL)
        {
            print_post_order_BinaryTree(&((*root)->left));
        }

        if ((*root)->right != NULL)
        {
            print_post_order_BinaryTree(&((*root)->right));
        }

        printf("%i\n", (*root)->data);
    }
}
