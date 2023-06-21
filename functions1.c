#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: stack
 * @line_number: line_num
 * @file: file opened
 * Return: none
 */

void swap(stack_t **stack, unsigned int line_number, FILE *file)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to stack
 * @line_number: line num
 * @file: file opened
 * Return: none
 */

void add(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number, file);
}

/**
 * nop - i do nothing, wAcK
 * Return: NoThInG
 */
void nop()
{
}

/**
 * sub - subtracts the top from second
 * @stack- pointer to stack
 * @line_number: line num
 * @file: file opened
 * Return: none
 */

void sub(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number, file);
}
