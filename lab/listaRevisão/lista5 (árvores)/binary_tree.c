#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "stack.h"

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

        Node *aux = (*root);
        if ((*root) == NULL)
        {
            (*root) = new;
            aux = (*root);
            return 1;
        }

        while (aux->left != NULL || aux->right != NULL)
        {
            if (data < aux->data)
            {
                if (aux->left == NULL)
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
                if (aux->right == NULL)
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
        else
        {
            free(new);
            return 0;
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

void free_Node(Node *no)
{
    if (no != NULL)
    {
        free_Node(no->left);
        free_Node(no->right);
        free(no);
    }
}

void free_BinaryTree(BinaryTree *raiz)
{
    if (raiz != NULL)
    {
        free_Node(*raiz);
        free(raiz);
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

int local_subtree(BinaryTree *a, BinaryTree *b)
{
    if (a == NULL || b == NULL || *a == NULL || *b == NULL)
    {
        return 0;
    }

    int igual_left;
    int igual_right;

    igual_left = is_subtree(&((*a)->left), &((*b)->left));
    igual_right = is_subtree(&((*a)->right), &((*b)->right));

    return (igual_left == igual_right) && ((*a)->data == (*b)->data);
}

int is_subtree(BinaryTree *a, BinaryTree *b)
{
    if (a == NULL || b == NULL || *a == NULL || *b == NULL)
    {
        return 0;
    }

    int sub = 0;
    sub = local_subtree(a, b) || is_subtree(&((*a)->right), b) || is_subtree(&((*a)->left), b);

    return sub;
}


void print_BinaryTree_Stack_post_order(BinaryTree *root)
{
    Stack *stack = create_Stack();
    Node *aux = (*root);
    Node *popped = (Node *)malloc(sizeof(Node));

    while (aux != NULL)
    {
        push(stack, aux);
        aux = aux->right;
    }
    // printf("Esquerda nulo.\n");
    while (!is_empty(stack))
    {
        // printf("Poppando e printando...\n");
        pop(stack, popped);
        printf("%i\n", popped->data);
        aux = popped->left;
        while (aux != NULL)
        {
            printf("%i\n", aux->data);
            aux = aux->left;
        }
    }
}


void print_BinaryTree_Stack_in_order(BinaryTree *root)
{
    Stack *stack = create_Stack();
    Node *aux = (*root);
    Node *popped = (Node *)malloc(sizeof(Node));

    while (aux != NULL)
    {
        push(stack, aux);
        aux = aux->left;
    }
    // printf("Esquerda nulo.\n");
    while (!is_empty(stack))
    {
        // printf("Poppando e printando...\n");
        pop(stack, popped);
        printf("%i\n", popped->data);
        aux = popped->right;
        while (aux != NULL)
        {
            printf("%i\n", aux->data);
            aux = aux->right;
        }
    }
    free_Stack(stack);
    free(popped);
}
