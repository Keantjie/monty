#include "monty.h"
/**
 * monty_mul - A function that multiply the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(8, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}

/**
 * monty_div - A function that divides the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(6, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - A function that modules the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(9, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		f_errors(7, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}

/**
 * monty_pchar - A function that prints char at top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	stack_t *temporary = *stack;

	if (!temporary)
	{
		f_errors(11, line_number);
		exit(EXIT_FAILURE);
	}
	number = temporary->n;
	if (number < 0 || number > 127)
	{
		f_errors(10, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temporary->n);
}

/**
 * monty_pstr - A function that prints the string starting at the top of the
 * stack, followed by a new line.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temporary = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (temporary != NULL)
	{
		if (temporary->n > 0 && temporary->n <= 127)
		{
			printf("%c", temporary->n);
			temporary = temporary->next;
		}
		else
			break;
	}
	printf("\n");
}
