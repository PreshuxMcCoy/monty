#include "monty.h"

/**
 * pall - print the elements of the stack
 * @stack: stack
 * @line_num: line_num
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	(void)line_num;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
