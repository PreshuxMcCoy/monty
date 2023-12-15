#include "monty.h"

/**
 * pop - delete the top most layer of the stack
 * @stack: stack
 * @line_num: line_num
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL;

	if (stack_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		(*stack)->next = NULL;
		free(*stack), *stack = NULL;
	}
	else
	{
		tmp = *stack;
		/*shouldn't stack -> next == NULL?*/
		*stack = (*stack)->prev;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp), tmp = NULL;
	}
}
