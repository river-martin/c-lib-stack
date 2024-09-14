#include "../src/stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

vp_stack _stack = { .top = NULL };

#define pop_intp(stack) ((int *) vp_stack_pop(stack))

/**
 * @brief Test the stack with int pointers.
 */
void test_int_stack(vp_stack *stack)
{
    for (int i = 0; i < 10; i++) {
        int *n = malloc(sizeof(int));
        *n     = i;
        vp_stack_push(stack, n);
    }
    for (int i = 9; i >= 0; i--) {
        int *p = pop_intp(stack);
        assert(p != NULL);
        assert(*p == i);
        free(p);
    }
    assert(stack->top == NULL);
    assert(vp_stack_pop(stack) == NULL);
    assert(stack->top == NULL);
    fprintf(stdout, "%s: passed\n", __func__);
}

/**
 * @brief Test the stack with char pointers.
 */
void test_str_stack(vp_stack *stack)
{
    char *strs[] = { "Hello", "World", "C", "Programming", "Language" };
    for (size_t i = 0; i < sizeof(strs) / sizeof(*strs); i++)
        vp_stack_push(stack, strs[i]);
    for (size_t i = sizeof(strs) / sizeof(*strs); i > 0; i--) {
        char *str = vp_stack_pop(stack);
        assert(str != NULL);
        assert(strcmp(str, strs[i - 1]) == 0);
    }
    assert(stack->top == NULL);
    assert(vp_stack_pop(stack) == NULL);
    assert(stack->top == NULL);
    fprintf(stdout, "%s: passed\n", __func__);
}

int main(void)
{
    vp_stack stack = { .top = NULL };
    test_int_stack(&stack);
    assert(stack.top == NULL);
    test_str_stack(&stack);
    assert(stack.top == NULL);
    vp_stack_pop(&stack);
    assert(stack.top == NULL);
    printf("All tests passed\n");
    return EXIT_SUCCESS;
}
