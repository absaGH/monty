#include "monty.h"

/**
 * opcode_swap - Swaps the top two nodes of the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line number from the script which is
 *               currently being processed
 *
 * Return: nothing
 */
void opcode_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);

	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	if (temp->next)
		temp->next->prev = (*stack);
	temp->next = (*stack);
	temp->prev = NULL;
	(*stack) = temp;
}

/**
 * opcode_add - Adds the values of the top two nodes of the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 * Return: nothing
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);

	}

	(*stack)->next->n += (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_nop - it does nothing
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Return: nothing
 */
void opcode_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
