#include "stack.h"

#include <stdlib.h>

vp_stack_t *vp_stack_new(void) {
	vp_stack_t *stack = malloc(sizeof(vp_stack_t));
	stack->top = NULL;
	return stack;
}

void vp_stack_push(vp_stack_t *stack, void *item)
{
    node_t *new_node = malloc(sizeof(node_t));
    *new_node        = (node_t){ .prev = stack->top, .item = item };
    stack->top       = new_node;
}

void *vp_stack_pop(vp_stack_t *stack)
{
    if (!stack->top) return NULL;
    node_t *top  = stack->top;
    void   *item = top->item;
    stack->top   = top->prev;
    free(top);
    return item;
}
