#include "../src/stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t _stack = { .top = NULL };

#define pop_intp(stack) ((int *) pop(stack))

/**
 * @brief Test the stack with int pointers.
 */
void test_int_stack(stack_t *stack)
{
    for (int i = 0; i < 10; i++) {
        int *n = malloc(sizeof(int));
        *n     = i;
        push(stack, n);
    }
    for (int i = 9; i >= 0; i--) {
        int *p = pop_intp(stack);
        assert(p != NULL);
        assert(*p == i);
        free(p);
    }
    assert(stack->top == NULL);
    assert(pop(stack) == NULL);
    assert(stack->top == NULL);
    fprintf(stdout, "%s: passed\n", __func__);
}

/**
 * @brief Test the stack with char pointers.
 */
void test_str_stack(stack_t *stack)
{
    char *strs[] = { "Hello", "World", "C", "Programming", "Language" };
    for (size_t i = 0; i < sizeof(strs) / sizeof(*strs); i++)
        push(stack, strs[i]);
    for (size_t i = sizeof(strs) / sizeof(*strs); i > 0; i--) {
        char *str = pop(stack);
        assert(str != NULL);
        assert(strcmp(str, strs[i - 1]) == 0);
    }
    assert(stack->top == NULL);
    assert(pop(stack) == NULL);
    assert(stack->top == NULL);
    fprintf(stdout, "%s: passed\n", __func__);
}

int main(void)
{
    stack_t stack = { .top = NULL };
    test_int_stack(&stack);
    assert(stack.top == NULL);
    test_str_stack(&stack);
    assert(stack.top == NULL);
    pop(&stack);
    assert(stack.top == NULL);
    printf("All tests passed\n");
    return EXIT_SUCCESS;
}