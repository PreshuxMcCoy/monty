#include "monty.h"

/**
 * swap - swap the top two elements of the slack
 * @stack: stack
 * @line_num: line_num
 */

void swap(stack_t **stack, unsigned int line_num)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = tmp;
}
