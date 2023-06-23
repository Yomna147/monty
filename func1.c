#include "monty.h"

/**
 * _add -> Adds the top two elements of the stack.
 * @stack: Stack.
 * @line_number: Line Number.
*/

void _add(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} num = (*stack)->next->n;
	num += (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = num;
}


/**
 * check -> Checks if the arguments are correct.
 * @ac: Argument Number.
 * @av: Argument Vector.
 * @file: File
*/

void check(int ac, char *av[], FILE *file)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

}


/**
 * execute -> Executes the opcode
 * @opcode: Opcode
 * @stack: Stack
 * @line_number: Line Number
*/

void execute(char *opcode, stack_t *stack, unsigned int line_number)
{
	int i;
	instruction_t command[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop}, {"swap", _swap}, {"add", _add},
		{"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl}, {NULL, NULL}
	};

	for (i = 0; command[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, command[i].opcode) == 0)
		{
			command[i].f(&stack, line_number);
			break;
		}
	}
	if (command[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

