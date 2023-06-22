#include <ctype.h>
#include "monty.h"

/**
 * mul -  multiplies the second top element by the top.
 * @stack: pointer to stack
 * @line_number: line_num
 *
 * Return: none
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - mod of second top element with top
 * @stack: pointer to stack
 * @line_number: line num
 *
 * Return: none
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to staxk
 * @line_number: line num
 * Return: none
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: cant't pchar, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (!isprint(value))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	putchar(value);
	putchar('\n');
}
