#include "shell.h"

/**
 * printStr - prints string of characters
 * @str: character pointer pointing  to char
 * Return: Returns string of  characters
 *
 */

void printStr(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
