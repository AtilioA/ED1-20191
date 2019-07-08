#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "stack.h"

int main()
{
    BinaryTree *binaryTree = create_BinaryTree();
    BinaryTree *root = create_BinaryTree();
    Stack *stack = create_Stack();
    printf("BinaryTree created.\n");

    printf("Inserting items...\n");
    insert_BinaryTree(binaryTree, 1);
    insert_BinaryTree(binaryTree, 2);
    insert_BinaryTree(binaryTree, 3);
    insert_BinaryTree(binaryTree, 4);
    insert_BinaryTree(binaryTree, 5);
    insert_BinaryTree(binaryTree, -4);
    insert_BinaryTree(binaryTree, -3);
    insert_BinaryTree(binaryTree, -5);
    insert_BinaryTree(binaryTree, -6);
    insert_BinaryTree(binaryTree, -2);

    insert_BinaryTree(root, -4);
    insert_BinaryTree(root, -3);
    insert_BinaryTree(root, -5);
    // insert_BinaryTree(root, 3);
    printf("Items inserted.\n");

    printf("\nPrinting in-order:\n");
    print_in_order_BinaryTree(binaryTree);

    printf("Printing in-order with stack...\n");
    print_BinaryTree_Stack_in_order(binaryTree);

    // printf("\nPrinting binaryTree, post-order:\n");
    // print_post_order_BinaryTree(binaryTree);

    // printf("Printing post-order with stack...\n");
    // print_BinaryTree_Stack_post_order(binaryTree);

    // printf("\nPrinting binaryTree, pre-order:\n");
    // print_pre_order_BinaryTree(binaryTree);
    // printf("\nroot é sub de tree? %d\n", is_subtree(binaryTree, root));

    free_BinaryTree(binaryTree);
    free_BinaryTree(root);
    free_Stack(stack);
    printf("\nBinary tree freed.\n");

    return 0;
}
