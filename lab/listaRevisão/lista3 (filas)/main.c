#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    LinkedList *queue = create_Queue();
    printf("Queue created.\n");

    printf("Enqueuing items...\n");
    enqueue(queue, 3);
    enqueue(queue, 28);
    enqueue(queue, 32);
    enqueue(queue, 0);
    enqueue(queue, 1);
    enqueue(queue, 7);
    printf("Items enqueued.\n");

    printf("Printing queue:\n");
    print_Queue(queue);

    printf("\nDequeuing items...");
    int dequeued = 0;
    dequeue(queue, &dequeued);
    printf("\n%i\n", dequeued);
    dequeue(queue, &dequeued);
    printf("%i\n", dequeued);
    dequeue(queue, &dequeued);
    printf("%i\n", dequeued);
    printf("Items dequeued.\n");

    printf("\nPrinting queue:\n");
    print_Queue(queue);

    free_Queue(queue);
    printf("\nQueue freed.\n");

    return 0;
}
