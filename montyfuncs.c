#include "monty.h"

/**
 * pall - print stack
 * @stack: ptr ptr to stack
 * @line_number: num of line where this func is called
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	print_stack(stack, line_number);
}

/**
 * pint - print top of stack
 * @stack: ptr ptr to stack
 * @line_number: num of line where this func is called
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	print_head(stack, line_number);
}

/**
 * swap - swap top 2 elts of stack
 * @stack: ptr ptr to stack
 * @line_number: num of line where this func is called
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		printerr(line_number, "can't swap, stack too short");
		return;
	}
	tmp->prev = tmp->next;
	tmp->next = tmp->next->next;

	tmp->prev->prev = NULL;
	tmp->prev->next = tmp;

	if (tmp->next)
		tmp->next->prev = tmp;

	*stack = tmp->prev;
}
