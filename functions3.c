#include "monty.h"

/**
 * rotr - rotated it to bottom
 * @stack: pointer to stack
 * @line_number: line num
 * Return: none
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	second_last = last;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
