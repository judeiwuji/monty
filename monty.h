#ifndef _MONTY_H_
#define _MONTY_H_
#define MAX_READ_SIZE 100
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct parser_s - linked list for parser
 * @data: string
 * @next: points to the next element
 *
 * Description: linked list node structure
 */
typedef struct parser_s
{
	char *data;
	struct parser_s *next;
} parser_t;
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_itoa(int num);
void print_errors(int n, ...);
void mem_error_check(void *data);
int isint(char *str);
int read_byte_codes(char *filename, char **b_code);
parser_t *parser(char *b_code);
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number);
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void process_code(stack_t **stack, char *b_code, int lineno);
void free_parsed(parser_t *head);
void free_stack(stack_t *head);
#endif
