#include "monty.h"

/**
 * push - push a new elt into the stack
 * @stack: ptr to ptr to the head of stack
 * @cmd: tokenized cmd
 * @is_stack: check if push to stack = 0 or queue = 1
 * @line_number: where this function is beeing called
 * Return: nothing
 */
void push(stack_t **stack, char **cmd, unsigned int line_number, int is_stack)
{
	if (cmd[1] && !cmd[2])
	{
		if (is_stack == 0)
			add_node_head(stack, atoi(cmd[1]));
		else
			add_node_end(stack, atoi(cmd[1]));
	}
	else
	{
		printerr(line_number, "usage: push integer");
	}
}

/**
 * pop - pop elt in head of statck
 * @stack: ptr to ptr to the head of stack
 * @line_number: where this function is beeing called
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	delete_node_head(stack);
	if (status < 0)
	{
		printerr(line_number, "can't pop an empty stack");
	}
}

/**
 * print_stack - print the content of the stack
 * @stack: ptr to ptr to the head of stack
 * @line_number: where this function is beeing called
 * Return: nothing
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	print_list(*stack);
	if (status < 0)
	{
		printerr(line_number, "Unknown error");
	}
}

/**
 * print_head - print elt in head of statck
 * @stack: ptr to ptr to the head of stack
 * @line_number: where this function is beeing called
 * Return: nothing
 */
void print_head(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		printerr(line_number, "can't pint, stack empty");
	}
	printf("%d\n", (*stack)->n);
}
