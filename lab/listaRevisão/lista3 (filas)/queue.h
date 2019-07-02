/* Linked list implementation of queue */

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

LinkedList *create_Queue();
void print_Queue(LinkedList *queue);
void enqueue(LinkedList *queue, int item);
void dequeue(LinkedList *queue, int *dequeued);
void free_Queue(LinkedList *queue);
