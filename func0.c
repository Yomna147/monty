#include "monty.h"

/**
 * _mod -> Modulo
 * @stack: Stack
 * @line_number: Line Number
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	int nm;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE); 
	} nm = (*stack)->next->n;
	if (nm == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	} nm = nm % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = nm;
}

/**
 * free_stack -> Frees the stack
 * @head: Stack Head
*/

void free_stack(stack_t *head)
{
	stack_t *nxt;

	while (head != NULL)
	{
		nxt = head->next;
		free(head);
		head = nxt;
	}
}
