#include "shell.h"



/**
 * _putchar - writes character to the stdout
 * @c: character to be printed
 * Return: Returns a character
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printstr - prints string of characters
 * @str: character pointer pointing  to char
 * Return: Returns string of  characters
 *
 */
void _printstr(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
