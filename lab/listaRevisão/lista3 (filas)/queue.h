/* Linked list implementation of queue */

#ifndef __QUEUE_H_
#define __QUEUE_H_


typedef struct Element
{
    int data;
    struct Element *next;
} Element;

typedef struct LinkedList
{
    Element *head;
    Element *tail;
    int size;
} LinkedList;

typedef LinkedList Queue;

Queue *create_Queue();
void print_Queue(Queue *queue);
void enqueue(Queue *queue, int item);
void dequeue(Queue *queue, int *dequeued);
void free_Queue(Queue *queue);

#endif
