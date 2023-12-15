#include "monty.h"

/**
 * _push_queue - adds a node to the queue
 * @stack: the node / head
 * @line_number: the line number
 */

void _push_queue(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void) line_number;

	/** head is the global variable for the stack or queue*/
	add_nodeint_queue(&head, (*stack)->n);
	free(tmp);
}

/**
 * add_nodeint_queue - adds a new node at the end of linked list
 * @stack: the head of the list
 * @n: the value of the node
 * Return: the address of the new element
 *	or NULL if it failed
 */

stack_t *add_nodeint_queue(stack_t **stack, int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *tmp = *stack;

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
		*stack = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new;
		new->prev = tmp;
	}

	return (new);
}
