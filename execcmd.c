#include "monty.h"

/**
 * execcmd - read file and executes cmds
 * @filename: name of the file to read cmds from
 * @stack: head ptr to stack
 * Return: nothing
 */
int execcmd(char *filename, stack_t **stack)
{
	FILE *stream;

	if (stack == NULL)
	{
		printerr(0, "Error: Stack address can't be null");
		return (status);
	}

	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		status = 1;
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (status);
	}
	get_inputs(stream, stack);
	fclose(stream);

	return (status);
}

/**
 * runcmd - execute the monty cmd
 * @cmd: ptr to cmd and list of args
 * @line_number: line where the cmd was red
 * @stack: head ptr to stack
 * @is_stack: check if push to stack = 0 or queue = 1
 * Return: execution status
 */
int runcmd(char **cmd, unsigned int line_number, stack_t **stack, int is_stack)
{
	int i = 0;
	instruction_t flist[] = {
		{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
		{"add", add}, {"sub", sub}, {"div", divide}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl}, {"rotr", rotr},
		{NULL, NULL}
	};

	if (strcmp("nop", cmd[0]) == 0)
		return (0);
	if (strcmp("push", cmd[0]) == 0)
	{
		push(stack, cmd, line_number, is_stack);
		return (0);
	}
	else
	{
		while (flist[i].opcode != NULL)
		{
			if (strcmp(flist[i].opcode, cmd[0]) == 0)
			{
				flist[i].f(stack, line_number);
				return (0);
			}
			i++;
		}
	}
	status = 1;
	fprintf(stderr, "L%u: unknown instruction", line_number);
	fprintf(stderr, " %s\n", *cmd);

	return (1);
}
