#ifndef __STACK_H_
#define __STACK_H_

#include "binary_tree.h"

typedef struct Element
{
    Node *node;
    struct Element *next;
} Element;

typedef struct LinkedList
{
    Element *head;
    int size;
} LinkedList;

typedef LinkedList Stack;

Stack *create_Stack();
int is_empty(Stack *stack);
void push(Stack *stack, Node *node);
void pop(Stack *stack, Node *popped);
void print_Stack(Stack *stack);
void free_Stack(Stack *stack);

#endif
