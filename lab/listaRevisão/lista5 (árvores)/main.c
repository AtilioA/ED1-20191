#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main()
{
    BinaryTree *binaryTree = create_BinaryTree();
    printf("BinaryTree created.\n");

    printf("Inserting items...\n");
    insert_BinaryTree(binaryTree, 9);
    insert_BinaryTree(binaryTree, 2);
    insert_BinaryTree(binaryTree, 0);
    insert_BinaryTree(binaryTree, 0);
    insert_BinaryTree(binaryTree, 5);
    insert_BinaryTree(binaryTree, 4);
    insert_BinaryTree(binaryTree, 0);
    insert_BinaryTree(binaryTree, 54);
    insert_BinaryTree(binaryTree, 0);
    insert_BinaryTree(binaryTree, 0);
    insert_BinaryTree(binaryTree, 3);
    printf("Items inserted.\n");

    printf("\nPrinting binaryTree, pre-order:\n");
    print_pre_order_BinaryTree(binaryTree);
    printf("\nPrinting binaryTree, in-order:\n");
    print_in_order_BinaryTree(binaryTree);
    printf("\nPrinting binaryTree, post-order:\n");
    print_post_order_BinaryTree(binaryTree);

    free_BinaryTree(binaryTree);
    printf("\nBinary tree freed.\n");

    return 0;
}
