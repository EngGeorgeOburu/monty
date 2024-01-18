#include "monty.h"

/**
 * add - sum top 2 elts of stack and place res at head, now size - 1
 * @stack: ptr ptr to stack
 * @line_number: num of line where this func is called
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		printerr(line_number, "can't add, stack too short");
		return;
	}
	sum = tmp->n + tmp->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * sub - subtract 2 first top elts of stack
 * @stack: ptr to stack
 * @line_number: number of line where the instruction is
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		printerr(line_number, "can't sub, stack too short");
		return;
	}

	res = tmp->next->n - tmp->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * divide - divide 2 first top elts of stack
 * @stack: ptr to stack
 * @line_number: number of line where the instruction is
 * Return: nothing
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		printerr(line_number, "can't div, stack too short");
		return;
	}

	if (tmp->n == 0)
	{
		printerr(line_number, "division by zero");
		return;
	}

	res = tmp->next->n / tmp->n;
	pop(stack, line_number);
	(*stack)->n = res;
}

/**
 * mul - multiply 2 first top elts of stack
 * @stack: ptr to stack
 * @line_number: number of line where the instruction is
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int prod;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		printerr(line_number, "can't mul, stack too short");
		return;
	}

	prod = tmp->next->n * tmp->n;
	pop(stack, line_number);
	(*stack)->n = prod;
}

/**
 * mod - divide 2 first top elts of stack
 * @stack: ptr to stack
 * @line_number: number of line where the instruction is
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int res;

	tmp = *stack;
	if (!tmp || !tmp->next)
	{
		printerr(line_number, "can't mod, stack too short");
		return;
	}

	if (tmp->n == 0)
	{
		printerr(line_number, "division by zero");
		return;
	}

	res = tmp->next->n % tmp->n;
	pop(stack, line_number);
	(*stack)->n = res;
}
