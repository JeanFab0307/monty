#include "monty.h"

/**
 * execute_opcode - executes the commands
 * @stack: stack
 * @opcode: the command
 * @l_n: line num
 *
 * Return: none
 */

void execute_opcode(stack_t **stack, const char *opcode, int l_n)
{
	int i;

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", divide}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr},
		/*add more here */
		{NULL, NULL}
	};
	if (opcode[0] == '#')
	{
		return;
	}
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, l_n);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l_n, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: Always
 */

int main(int argc, char *argv[])
{
	stack_t *stack;
	unsigned int line_number = 1;
	char line[256], *opcode;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	stack = NULL;
	line_number = 1;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		opcode = strtok(line, " ");
		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue; /* empty line move to next */
		}
		execute_opcode(&stack, opcode, line_number);
		line_number++;
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
