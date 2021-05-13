#include "monty.h"
#include <ctype.h>

/**
 * check_digit - checks that a string only contains digits
 * @arg: string to be checked
 *
 * Return: 0 if only digits, otherwise 1
 */
static int check_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
	}
	return (0);
}


/**
 * opcode_push - Pushes a value to the top of the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line number from the script which is
 *              currently being processed
 *
 * Return: nothing
 */
void opcode_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new;
	int n;
	char *arg;

	arg = strtok(NULL, DELIMS);
	if (arg == NULL || check_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if ((*stack) == NULL)
	{
		new->prev = new->next = NULL;
		(*stack) = new;
	}
	else if (mod == 0)
	{
		temp = (*stack);
		(*stack)->prev = new;
		new->next = temp;
		new->prev = NULL;
		(*stack) = new;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->prev = temp;
		new->next = NULL;
		temp->next = new;
	}
}
/**
 * opcode_pall - Prints the content of the stack
 * @stack: A pointer to the top node of a stack
 * @line_number: The line number from the script which is
 *              currently being processed
 *Return: nothing
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);

	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * opcode_pint - Prints the top value of the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line number from the script which is
 *              currently being processed
 *
 *Return: nothing
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * opcode_pop - Removes the top node from the stack
 * @stack: A pointer to the top node of the stack
 * @line_number: The line number from the script which is
 *              curretnly being processed
 *
 *Return: nothing
 */
void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);

	}

	next = (*stack)->next;
	free((*stack));
	if (next)
		next->prev = NULL;
	(*stack) = next;
}
