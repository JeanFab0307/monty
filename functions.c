#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack
 * @line_number: linenum
 * Return: none
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	stack_t *new_n;
	int val;

	arg = strtok(NULL, " ");
	if (arg == NULL)
	{
		fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = atoi(arg);
	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_n->n = val;
	new_n->prev = NULL;
	new_n->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_n;
	*stack = new_n;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: stack
 * @line_number: linenumber
 * Return: none
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top
 * @stack: pointer to the stack
 * @line_number: current line num
 * Return: none
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}