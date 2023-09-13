#include "shell.h"

/**
 * _putchar - writes character to the stdout
 * @c: character to be printed
 * Return: Return a character
 *
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
