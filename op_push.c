#include "monty.h"

/**
 * op_push - Pushes an item to top of the stack
 * @stack: stack_t
 * @line_number: int
 *
 * Return: void
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	stack_t *head;

	node = malloc(sizeof(stack_t));
	mem_error_check(node);
	node->n = line_number;
	node->next = NULL;
	node->prev = NULL;
	if ((*stack) != NULL)
	{
		head = (*stack);
		node->next = head;
		head->prev = node;
	}
	(*stack) = node;
}
