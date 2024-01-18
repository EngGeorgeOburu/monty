#include "monty.h"

/**
 * pchar - read top of stack as char
 * @stack: ptr to stack
 * @line_number: number of the line where cmd found
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		printerr(line_number, "can't pchar, stack empty");
		return;
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		printerr(line_number, "can't pchar, value out of range");
		return;
	}

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - read stack as string
 * @stack: ptr to stack
 * @line_number: number of the line where cmd found
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack ||  line_number == 0)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp)
	{
		if (tmp->n < 0 || tmp->n > 127 || tmp->n == 0)
		{
			break;
		}
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotr - read stack as string
 * @stack: ptr to stack
 * @line_number: number of the line where cmd found
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next ||  line_number == 0)
	{
		return;
	}

	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}

/**
 * rotl - read stack as string
 * @stack: ptr to stack
 * @line_number: number of the line where cmd found
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (!stack || !*stack || !(*stack)->next || line_number == 0)
	{
		return;
	}

	tmp = *stack;
	tmp2 = tmp;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = tmp2;
	tmp2->prev = tmp;
	tmp2->next = NULL;
}
