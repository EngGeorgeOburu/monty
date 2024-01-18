#include "monty.h"

/**
 * get_inputs - read user inputs from stdin and parse lines
 * @stream: file descriptor to read cmds from, if any
 * @stack: head ptr to stack
 * Return: execution status
 */
int get_inputs(FILE *stream, stack_t **stack)
{
	size_t size = 0, hasred = 0;
	ssize_t nread;
	char *buffer = NULL, **toks;
	unsigned int line_number = 1;
	int is_stack = 0, tmp;

	do {
		nread = getline(&buffer, &size, stream);
		if (nread >= 0)
		{
			hasred = 1;
			toks = _strtok(buffer, nread + 1, " \n\t");
			tmp = isstack(toks);
			if (tmp >= 0)
			{
				is_stack = tmp;
				free_toks(toks);
			}
			else if (toks && *toks && tmp < 0)
			{
				runcmd(toks, line_number, stack, is_stack);
				free_toks(toks);
				if (status != 0)
				{
					break;
				}
			}
			line_number++;
		}
		else if (nread < 0 && !hasred)
		{
			printerr(line_number, "Failed to read instrucation");
		}
	} while (nread != -1);
	free(buffer);

	return (status);
}

/**
 * isstack - determine if the cmd is stack, queue or other
 * @toks: char ptr to tokens
 * Return: 0 if stack, 1 if queue, -1 otherwise
 */
int isstack(char **toks)
{
	if (!toks || !*toks)
		return (-1);
	if (strcmp(toks[0], "stack") == 0 && toks[1] == NULL)
		return (0);
	if (strcmp(toks[0], "queue") == 0 && toks[1] == NULL)
		return (1);
	return (-1);
}
