#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

BinaryTree *create_BinaryTree()
{
    BinaryTree *new = (BinaryTree *)malloc(sizeof(BinaryTree));

    (*new) = NULL;

    return new;
}

int insere_BinaryTree(BinaryTree* raiz, int valor)
{
    if (raiz != NULL)
    {
        Node *novo = malloc(sizeof(Node));
        novo->left = NULL;
        novo->right = NULL;
        novo->data = valor;
        Node *aux = (*raiz);

        if ((*raiz) == NULL)
        {
            (*raiz) = novo;
            return 1;
        }

        while(aux->left != NULL || aux->right != NULL)
        {
            if (valor < aux->data)
            {
                if (aux->left == NULL)
                {
                    break;
                }
                aux = aux->left;
            }
            else if (valor > aux->data)
            {
                if (aux->right == NULL)
                {
                    break;
                }
                aux = aux->right;
            }
            else
            {
                return 0; // Valor já presente na árvore
            }

        }

        if (valor < aux->data)
        {
            aux->left = novo;
            return 1;
        }
        else if (valor > aux->data)
        {
            aux->right = novo;
            return 1;
        }

    }
    else
    {
        return 0;
    }
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
        printf("%d\n", (*root)->data);
        if((*root)->left != NULL)
        {
            print_pre_order_BinaryTree(&((*root)->left));
        }
        if((*root)->right != NULL)
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
            print_pre_order_BinaryTree(&((*root)->left));
        }

        printf("%i", (*root)->data);

        if ((*root)->right != NULL)
        {
            print_pre_order_BinaryTree(&((*root)->right));
        }
    }
}

void preOrdem_BinaryTree(BinaryTree *raiz)
{
    if (raiz != NULL)
    {
        printf("%d\n", (*raiz)->data);
        if((*raiz)->left != NULL)
        {
            preOrdem_BinaryTree(&((*raiz)->left));
        }
        if((*raiz)->right != NULL)
        {
            preOrdem_BinaryTree(&((*raiz)->right));
        }
    }
}

/** Imprime em-ordem */
void emOrdem_BinaryTree(BinaryTree *raiz)
{
    if (raiz != NULL)
    {
        if((*raiz)->left != NULL)
        {
            preOrdem_BinaryTree(&((*raiz)->left));
        }
        printf("%d\n", (*raiz)->data);
        if((*raiz)->right != NULL)
        {
            preOrdem_BinaryTree(&((*raiz)->right));
        }
    }
}
