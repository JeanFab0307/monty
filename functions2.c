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

/**
 * mod - mod of second top element with top
 * @stack: pointer to stack
 * @line_number: line num
 * @file: file
 * Return: none
 */

void mod(stack_t **stack, unsigned int line_number, FILE *file)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number, file);
}
