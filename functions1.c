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
