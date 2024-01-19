#include "monty.h"

/**
 * printerr - print error message to stderr and set status to 1
 * @msg: error message to be printed
 * @line_number: error status code
 * Return: nothing
 */
void printerr(unsigned int line_number, const char *msg)
{
	if (line_number != 0)
		fprintf(stderr, "L%u: %s\n", line_number, msg);
	else
		fprintf(stderr, "%s\n", msg);
	status = 1;
}
