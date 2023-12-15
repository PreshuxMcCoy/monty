#include "monty.h"

/**
 * divide - div divides the second top element of the stack by the top
 * element of the stack.
 * and operate pop, unless top == zero
 * @stack: stack
 * @line_num: line_num
 */
void divide(stack_t **stack, unsigned int line_num)
{
	int divide_result = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	divide_result = (*stack)->prev->n / (*stack)->n;
	(*stack)->prev->n = divide_result;
	pop(stack, line_num);
}
