#include "monty.h"

/**
 * process_code - Process a given bytecode
 * @stack: The current stack
 * @b_code: The bytecode to be processed
 * @lineno: The current line being interpreted
 *
 * Return: void
 */
void process_code(stack_t **stack, char *b_code, int lineno)
{
	int arg;
	parser_t *parsed, *parsed_arg;
	void (*op)(stack_t **stack, unsigned int line_number) = NULL;

	parsed = parser(b_code);
	if (parsed != NULL)
	{
		op = get_op_func(parsed->data);
		if (op == NULL)
		{
			print_errors(5, "L", _itoa(lineno), ": unknown instruction ",
						 parsed->data, "\n");
			exit(EXIT_FAILURE);
		}
		arg = 0;
		if (strcmp(parsed->data, "push") == 0)
		{
			parsed_arg = parsed->next;
			if (parsed_arg == NULL || isint(parsed_arg->data) == 0)
			{
				print_errors(3, "L", _itoa(lineno), ": usage: push integer\n");
				exit(EXIT_FAILURE);
			}
			arg = atoi(parsed_arg->data);
		}
		op(stack, arg);
	}
	free_parsed(parsed);
}
