#include "monty.h"

/**
 * opcode_pchar - prints the character equivalent of the values of the top node
 *                from the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 * Return: nothing
 */
void opcode_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * opcode_pstr - prints the string contained in the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 * Return: nothing
 */
void opcode_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);

	while (temp && temp->n != 0 && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
	(void)line_number;
}

/**
 * opcode_rotl - Rotates the top value of the stack the last one, and
 *          the second top element of the stack becomes the first one
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void opcode_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	top = (*stack);
	bottom = (*stack);
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = NULL;
	(*stack) = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * opcode_rotr - Rotates the bottom value of the stack to the top
 * @stack: A pointer to the top node of the stack
 * @line_number: The current working line number of a Monty bytecodes file
 *
 * Return: nothing
 */
void opcode_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	top = (*stack);
	bottom = (*stack);
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack) = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}
