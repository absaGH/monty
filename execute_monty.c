#include "monty.h"

/**
 * run_opcode - it checks op against valid opcodes &
 *              calls the respective function
 * @op: opcode to be checked against valid opcodes
 * @stack: double pointer to the beginnig of the stack
 * @line_number: the line number of the opcode in the script
 *
 * Return: nothing
 */
void run_opcode(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t opcodes[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
		{"pint", opcode_pint},
		{"pop",  opcode_pop},
		{"swap", opcode_swap},
		{"add",  opcode_add},
		{"nop",  opcode_nop},
		{"sub",  opcode_sub},
		{"div",  opcode_div},
		{"mul",  opcode_mul},
		{"mod",  opcode_mod},
		{"pchar", opcode_pchar},
		{"pstr", opcode_pstr},
		{"rotl", opcode_rotl},
		{"rotr", opcode_rotr},
		{"stack", opcode_stack},
		{"queue", opcode_queue},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, op) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * execute_monty - Driver function to execute a Monty bytecodes script.
 * @monty_file: File handle for an open Monty bytecodes script.
 *
 * Return: nothing
 */
void execute_monty(FILE *monty_file)
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *line = NULL, *opcode = NULL;
	size_t n = 0;

	while (getline(&line, &n, monty_file) != -1)
	{
		line_number++;
		opcode = strtok(line, "\n\t\r ");
		if (opcode != NULL && opcode[0] != '#')
		{
			run_opcode(opcode, &stack, line_number);
		}
	}
	if (line != NULL)
		free(line);
	free_stack(&stack);
}
