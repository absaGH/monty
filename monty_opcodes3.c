#include "monty.h"

/**
 * opcode_sub - substracts the values of the top two nodes of the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 * Return: nothing
 */
void opcode_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_div - Divides the second value from the top of
 *             the stack by the top value
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 * Return: nothing
 */
void opcode_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_mul - Multiplies the values of the top two nodes of the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 * Return: nothing
 */
void opcode_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	opcode_pop(stack, line_number);
}

/**
 * opcode_mod - calculates the modulus of values of the top
 *             two nodes of the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line from the script which is currently being processed
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 * Return: nothing
 */
void opcode_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	opcode_pop(stack, line_number);
}
