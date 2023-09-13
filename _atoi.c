#include "main.h"





/**
 * is_interactive - check whether shell is active or not
 * Return: Returns (1) if active  mode otherwise (0) inactive
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO));
}

