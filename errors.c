#include "main.h"




/**
 * print_error - prints an error message
 * @filename: file name
 * @line_count: count the number of line
 * @cmd: the command
 * @estr: the string
 * Return: Return (0) if no numbers in string, otherwise (-1)
 */
void print_error(const char *filename, int line_count,
		const char *cmd, const char *estr)
{
	fprintf(stderr, "%s: %d: %s: %s\n", filename, line_count, cmd, estr);
}
