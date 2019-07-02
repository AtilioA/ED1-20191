#ifndef __STACK_H_
#define __STACK_H_

typedef struct Element
{
    int data;
    struct Element *next;
} Element;

typedef struct LinkedList
{
    Element *head;
    int size;
} LinkedList;

typedef LinkedList Stack;

Stack *create_Stack();
void push(Stack *stack, int data);
void pop(Stack *stack, int *popped);
void print_Stack(Stack *stack);
void free_Stack(Stack *stack);

#endif
