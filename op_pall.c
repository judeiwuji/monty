#include "monty.h"

/**
 * op_pall - Prints all item in the stack
 * @stack: The stack to be pushed item to
 * @line_number: The data
 *
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *node;

	node = (*stack);
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
