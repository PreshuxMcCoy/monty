#include "monty.h"

/**
 * rotl - prints the string starting at the top of the stack, followed
 * by a new line, while the integer being treated as an ascii value
 * @stack: stack
 * @line_num: line_num
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL, *initial = NULL;

	(void)line_num;
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		return;
	}
	initial = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	initial->prev = NULL;
	initial->next = NULL;
	tmp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = initial;
	initial->next = tmp;
}
