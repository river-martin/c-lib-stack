#ifndef _STACK_H
#define _STACK_H

/**
 * @brief A simple linked list implementation of a last in, first out stack of
 * void pointers.
 */

/**
 * @brief A node in the stack.
 */
typedef struct __node {
    void          *item; /**< The item at the top of the stack */
    struct __node *prev; /**< A pointer to the node below this one */
} node_t;

typedef struct __stack {
    node_t *top; /**< A pointer to the node at the top of the stack */
} vp_stack;

/**
 * @brief Create and initialize a new `void *` stack
 */
extern vp_stack *vp_stack_new(void);

/**
 * @brief Add an item to the top of the given stack.
 *
 * @param stack The stack to push to.
 * @param item The item to push.
 */
extern void vp_stack_push(vp_stack *stack, void *item);

/**
 * @brief Remove an item from the top of the stack and return it.
 *
 * @param stack The stack to pop from.
 * @return The item at the top of the stack.
 */
extern void *vp_stack_pop(vp_stack *stack);

#endif // _STACK_H
