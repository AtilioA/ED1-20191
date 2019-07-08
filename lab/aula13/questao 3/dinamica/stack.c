#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "stack.h"

Stack *create_Stack()
{
    Stack *new = (Stack *)malloc(sizeof(Stack));

    new->head = NULL;
    new->size = 0;

    return new;
}

int is_empty(Stack *stack)
{
    return stack->size == 0;
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
        Element *helper = stack->head;
        Element *new = (Element *)malloc(sizeof(Element));
        new->data = data;
        stack->head = new;
        stack->head->next = helper;
    }
    stack->size++;
}

void pop(Stack *stack, int *popped)
{
    if (stack->head != NULL)
    {
        Element *helper = stack->head;
        stack->head = stack->head->next;

        *popped = helper->data;
        free(helper);
        stack->size--;
    }
}

void print_Stack(Stack *stack)
{
    if (stack != NULL && stack->head != NULL && stack->size != -1)
    {
        Element *helper = stack->head;

        while (helper != NULL)
        {
            printf("%i\n", helper->data);
            helper = helper->next;
        }
        printf("Stack size: %i\n", stack->size);
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

void *insertion_sort_Stack(Stack *stack, int element)
{
    if (is_empty(stack) || element < stack->head->data)
    {
        push(stack, element);
    }
    else
    {
        int temp;
        pop(stack, &temp);
        insertion_sort_Stack(stack, element);
        push(stack, temp);
    }
}

void sort_Stack(Stack *stack)
{
    if (!is_empty(stack))
    {
        int temp;
        pop(stack, &temp);
        sort_Stack(stack);
        insertion_sort_Stack(stack, temp);
    }
}
