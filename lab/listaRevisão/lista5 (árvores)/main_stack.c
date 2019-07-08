#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int mains()
{
    Stack *stack = create_Stack();
    printf("Stack created.\n");

    printf("Pushing items...\n");
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = 2;
    push(stack, new);

    Node *new2 = (Node *)malloc(sizeof(Node));
    new2->data = 3;
    push(stack, new2);

    Node *new3 = (Node *)malloc(sizeof(Node));
    new3->data = 102;
    push(stack, new3);

    Node *new4 = (Node *)malloc(sizeof(Node));
    new4->data = 0;
    push(stack, new4);

    Node *new5 = (Node *)malloc(sizeof(Node));
    new5->data = -3;
    push(stack, new5);

    Node *new6 = (Node *)malloc(sizeof(Node));
    new6->data = 9;
    push(stack, new6);
    printf("Items pushed.\n");

    printf("Printing stack:\n");
    print_Stack(stack);

    printf("\nPopping items...");
    Node *popped = (Node *)malloc(sizeof(Node));

    pop(stack, popped);
    printf("\n%i\n", popped->data);
    pop(stack, popped);
    printf("%i\n", popped->data);
    pop(stack, popped);
    printf("%i\n", popped->data);
    printf("Items popped.\n");

    printf("\nPrinting stack:\n");
    print_Stack(stack);

    free_Stack(stack);
    free(popped);
    free(new4);
    free(new5);
    free(new6);
    printf("\nStack freed.\n");

    return 0;
}
