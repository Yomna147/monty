#include "monty.h"

/**
 * _pall -> Prints all the values on the stack
 * @stack: Stack
 * @line_number: Line Number
*/

void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *num;

	for (num = *stack; num != NULL; num = num->next)
		printf("%d\n", num->n);
}


/**
 * _pop -> Removes the top element of the stack
 * @stack: Stack
 * @line_number: Line Number
*/

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	} tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}



/**
 * _sub -> Subtract the top and second top elements of the stack
 * @stack: Stack
 * @line_number: Line Number
*/

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *num;
	int sub;

	num = *stack;
	if (num == NULL || num->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} sub = num->next->n - num->n;
	num->next->n = sub;
	_pop(stack, line_number);
}


/**
 * pstr -> Print the string starting at the top of the stack..	
 * @head: Stack Head.
 * @counter: Line Number.
 */

void pstr(stack_t **head, unsigned int counter)
{
    stack_t *tmp = *head;

    (void)counter;
    while (tmp != NULL)
    {
        if (tmp->n <= 0 || tmp->n > 127)
            break;
        printf("%c", tmp->n);
        tmp = tmp->next;
    } printf("\n");
}


/**
 * _swap -> Swaps the top two elements of the stack
 * @stack: Stack
 * @line_number: Line Number
*/

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *num;
	int _switch;

	num = *stack;
	if (num == NULL || num->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	} _switch = num->n;
	num->n = num->next->n;
	num->next->n = _switch;
}
