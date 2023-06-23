#include "monty.h"

/**
 * _pint -> Prints the value at the top of the stack
 * @stack: Stack
 * @line_number: Line Number
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *num;

	num = *stack;
	if (num == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	} printf("%d\n", num->n);
}


/**
 * _nop -> Does nothing
 * @stack: Stack
 * @line_number: Line Number
*/

void _nop(__attribute__ ((unused))stack_t **stack,
	  __attribute__ ((unused))unsigned int line_number)
{
	;
}


/**
 * pchar -> Print the char at the top of the stack...
 * @head: Stack Head.
 * @counter: Line Number.
 */

void pchar(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        exit(EXIT_FAILURE);
    }
    if ((*head)->n < 0 || (*head)->n > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        exit(EXIT_FAILURE);
    } printf("%c\n", (*head)->n);
}

/**
 * rotl -> Rotates the stack to the top
 * @head: Stack Head
 * @counter: Line Number
 */

void rotl(stack_t **head, unsigned int counter)
{
    stack_t *tmp = *head;
    int n;

    (void)counter;
    if (*head == NULL || (*head)->next == NULL)
        return;
    n = (*head)->n;
    while (tmp->next != NULL)
    {
        tmp->n = tmp->next->n;
        tmp = tmp->next;
    } tmp->n = n;
}


/**
 * _mul -> Multiplies the top two elements of the stack.
 * @stack: Stack.
 * @line_number: Line Number.
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	int num;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} num = (*stack)->next->n;
	num *= (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = num;
}


