#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

LinkedList *create_Queue()
{
    LinkedList *queue = (LinkedList *)malloc(sizeof(LinkedList));

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void enqueue(LinkedList *queue, int item)
{
    if (queue->head == NULL)
    {
        queue->head = (Element *)malloc(sizeof(Element));
        queue->head->data = item;
        queue->head->next = NULL;

        queue->tail = queue->head;

        queue->size++;

    }
    else
    {
        Element *new = (Element *)malloc(sizeof(Element));
        new->data = item;
        new->next = NULL;
        queue->tail->next = new;
        queue->tail = queue->tail->next;
        queue->size++;
    }
}

void dequeue(LinkedList *queue, int *dequeued)
{
    if (queue->head != NULL)
    {
        Element *aux = queue->head;
        queue->head = queue->head->next;

        *dequeued = aux->data;
        free(aux);
    }
}

void print_Queue(LinkedList *queue)
{
    Element *aux = queue->head;

    while (aux != NULL)
    {
        printf("%i\n", aux->data);
        aux = aux->next;
    }
}

void free_Queue(LinkedList *queue)
{
    Element *current = queue->head;
    Element *previous;
    while (queue->head != NULL)
    {
        previous = current;
        current = current->next;
        free(previous);
    }
    free(queue);
}
