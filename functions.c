#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack
 * @line_number: linenum
 * @file: file
 * Return: none
 */

void push(stack_t **stack, unsigned int line_number, FILE *file)
{
	char *arg;
	stack_t *new_n;
	int val, i;

	arg = strtok(NULL, " ");
	if (arg == NULL)
	{
		fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* chek if it is num */
	for (i = 0; arg[i] != '\0'; i++)
	{
		if (!isdigit(arg[i]) && arg[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	val = atoi(arg);
	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(file);
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
 * @file: file
 * Return: none
 */

void pall(stack_t **stack, unsigned int line_number, FILE *file)
{
	stack_t *current;

	(void)file;
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
 * @file: file
 * Return: none
 */

void pint(stack_t **stack, unsigned int line_number, FILE *file)
{
	(void)file;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * free_stack - frees unfreed memo
 * @stack: stack
 * Return: none
 */

void free_stack(stack_t *stack)
{
	stack_t *current, *temp;

	current = stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 * pop - removes the top element of the stack.
 * @stack: stack
 * @line_number: line_num
 * @file: file opened
 * Return: none
 */

void pop(stack_t **stack, unsigned int line_number, FILE *file)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
