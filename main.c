#include "monty.h"

int status;

/**
 * main - entry point of the monty interpretor
 * @argc: argument count
 * @argv: argument values
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	status = 0;

	if (argc != 2)
	{
		printerr(0, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	if (execcmd(argv[1], &stack) == 1)
	{
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	free_stack(stack);
	return (status);
}
