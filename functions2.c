#include "monty.h"

/**
 * mul -  multiplies the second top element by the top.
 * @stack: pointer to stack
 * @line_number: line_num
 * @file: file opened
 * Return: none
 */

void mul(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number, file);
}
