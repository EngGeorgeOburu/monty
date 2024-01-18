#include "monty.h"

/**
 * printerr - print error message to stderr and set status to 1
 * @msg: error message to be printed
 * @line_number: error status code
 * Return: nothing
 */
void printerr(unsigned int line_number, const char *msg)
{
	fprintf(stderr, "L%u: %s\n", line_number, msg);
	status = 1;
}
