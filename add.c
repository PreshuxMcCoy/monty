#include "monty.h"

/**
 * add - Add first layer data to the second top one, and
 * remove the top
 * @stack: stack
 * @line_num: line_num
 */
void add(stack_t **stack, unsigned int line_num)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n + (*stack)->prev->n;
	(*stack)->prev->n = tmp;
	pop(stack, line_num);
}
