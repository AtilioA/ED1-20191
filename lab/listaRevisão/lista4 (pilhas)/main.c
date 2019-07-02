#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack *stack = create_Stack();
    printf("Stack created.\n");

    printf("Pushing items...\n");
    push(stack, 2);
    push(stack, 3);
    push(stack, 102);
    push(stack, 0);
    push(stack, -3);
    push(stack, 9);
    printf("Items pushed.\n");

    printf("Printing stack:\n");
    print_Stack(stack);

    printf("\nPopping items...");
    int popped = 0;
    pop(stack, &popped);
    printf("\n%i\n", popped);
    pop(stack, &popped);
    printf("%i\n", popped);
    pop(stack, &popped);
    printf("%i\n", popped);
    printf("Items popped.\n");

    printf("\nPrinting stack:\n");
    print_Stack(stack);

    free_Stack(stack);
    printf("\nStack freed.\n");

    return 0;
}
