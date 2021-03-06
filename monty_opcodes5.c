#include "monty.h"

/**
 * opcode_stack - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: the line number in the script i.e. currently being processed
 *
 * Return: nothing
 */
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mod = 0;
}

/**
 * opcode_queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: the line number in the script currently being processed
 *
 * Return: nothing
 */
void opcode_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	mod = 1;
}
