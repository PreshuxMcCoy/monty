#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the
 * top element of the stack.
 * and operate pop.
 * @stack: stack
 * @line_num: line_num
 */
void mul(stack_t **stack, unsigned int line_num)
{
	int mul_result = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	mul_result = (*stack)->prev->n * (*stack)->n;
	(*stack)->prev->n = mul_result;
	pop(stack, line_num);
}
