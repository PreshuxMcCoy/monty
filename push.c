#include "monty.h"

/**
 * push - push element to the stack
 * @stack: stack
 * @line_num: line_num
 */

void push(stack_t **stack, unsigned int line_num)
{
	stack_t *top = malloc(sizeof(stack_t));

	(void)line_num;
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	top->n = return_arg();
	top->next = NULL;
	top->prev = *stack;
	if (!stack_empty(*stack))
	{
		(*stack)->next = top;
	}
	*stack = top;
}
