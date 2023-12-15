#include "monty.h"

/**
 * sub - subtract the top from the second to layer
 * and operate pop
 * @stack: stack
 * @line_num: line_num
 */
void sub(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n = (*stack)->prev->n - (*stack)->n;
	pop(stack, line_num);
}
