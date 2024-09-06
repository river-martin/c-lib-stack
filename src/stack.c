#include "stack.h"

#include <stdlib.h>

void push(stack_t *stack, void *item)
{
    node_t *new_node = malloc(sizeof(node_t));
    *new_node        = (node_t){ .prev = stack->top, .item = item };
    stack->top       = new_node;
}

void *pop(stack_t *stack)
{
    if (!stack->top) return NULL;
    node_t *top  = stack->top;
    void   *item = top->item;
    stack->top   = top->prev;
    free(top);
    return item;
}
