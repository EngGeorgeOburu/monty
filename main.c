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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	execcmd(argv[1], &stack);
	free_stack(stack);

	return (status);
}
