#include "monty.h"

/**
 * op_swap - Swaps the last two items in the stack
 * @stack: The stack to be pushed item to
 * @line_number: The data
 *
 * Return: void
 */
void op_swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head;
	stack_t *node;
	stack_t *temp;

	if (stack == NULL)
		return;
	head = (*stack);
	node = head->next;
	temp = head;
	head = node;
	node = temp;
	node->prev = head;
	node->next = head->next;
	head->next = node;
	head->prev = NULL;
	*stack = head;
}
