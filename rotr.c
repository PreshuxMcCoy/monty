#include "monty.h"

/**
 * rotr - prints the string starting at the top of the stack, followed
 * by a new line, while the integer being treated as an ascii value
 * @stack: stack
 * @line_num: line_num
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = NULL, *initial = *stack, *final = NULL;
	(void)line_num;
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp->prev->prev != NULL)
		tmp = tmp->prev;
	final = tmp->prev;
	final->next = NULL;
	tmp->prev = NULL;
	final->prev = initial;
	initial->next = final;
	*stack = final;
}
