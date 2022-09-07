#include "monty.h"

/**
 * get_op_func - Gets the function to perform a given operation
 * @opcode: The operation code to be performed
 *
 * Return: pointer function if found, NULL otherwise
 */
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{NULL, NULL},
	};
	int i;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			return (opcodes[i].f);
	}
	return (NULL);
}