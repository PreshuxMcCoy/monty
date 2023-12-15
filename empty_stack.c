#include "monty.h"

/**
 * empty_stack - free stack
 * @stack: stack
 */
void empty_stack(stack_t **stack)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->prev;
		free(tmp), tmp = NULL;
	}
}
