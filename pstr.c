#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack, followed
 * by a new line, while the integer being treated as an ascii value
 * @stack: stack
 * @line_num: line_num
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	(void)line_num;
	if (tmp == NULL)
	{
		putchar('\n');
		return;
	}

	while (tmp && (tmp->n < 128 && tmp->n > 0))
	{
		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->prev;
	}
	putchar('\n');
}
