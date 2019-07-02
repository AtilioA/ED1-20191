#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *create_Stack()
{
    Stack *new = (Stack *)malloc(sizeof(Stack));

    new->head = NULL;
    new->size = 0;

    return new;
}

void push(Stack *stack, int data)
{
    if (stack->head == NULL)
    {
        stack->head = (Element *)malloc(sizeof(Element));
        stack->head->data = data;
        stack->head->next = NULL;
    }
    else
    {
        Element *aux = stack->head;
        Element *new = (Element *)malloc(sizeof(Element));
        new->data = data;
        stack->head = new;
        stack->head->next = aux;
    }
    stack->size++;
}

void pop(Stack *stack, int *popped)
{
    if (stack->head != NULL)
    {
        Element *aux = stack->head;
        stack->head = stack->head->next;

        *popped = aux->data;
        free(aux);
        stack->size--;
    }
}

void print_Stack(Stack *stack)
{
    if (stack != NULL && stack->head != NULL && stack->size != -1)
    {
        Element *aux = stack->head;

        while (aux != NULL)
        {
            printf("%i\n", aux->data);
            aux = aux->next;
        }
        printf("Stack size: %i", stack->size);
    }
}

void free_Stack(Stack *stack)
{
    Element *current = stack->head;
    Element *previous;

    while (current != NULL)
    {
        previous = current;
        current = current->next;
        free(previous);
    }
    stack->size = -1;
    free(stack);
}
