#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef Node* BinaryTree;

BinaryTree *create_BinaryTree();
int insert_BinaryTree(BinaryTree *root, int data);
void print_pre_order_BinaryTree(BinaryTree *root);
void print_in_order_BinaryTree(BinaryTree *root);
void print_post_order_BinaryTree(BinaryTree *root);
void print_BinaryTree_Stack_in_order(BinaryTree *root);
void print_BinaryTree_Stack_post_order(BinaryTree *root);
void free_BinaryTree(BinaryTree *root);
int is_subtree(BinaryTree *a, BinaryTree *b);

#endif
