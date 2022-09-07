#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom.
 * @stack: stack_t
 * @line_number: int
 *
 * Return: void
 */
void op_rotr(stack_t **stack, unsigned int line_number
			 __attribute__((unused)))
{
	stack_t *tail, *node, *temp;

	tail = (*stack);
	if (tail == NULL)
		return;
	while (tail->next != NULL)
		tail = tail->next;
	node = tail;
	while (node != NULL)
	{
		temp = node->prev;
		node->prev = node->next;
		node->next = temp;
		node = temp;
	}
	tail->prev = NULL;
	(*stack) = tail;
}
