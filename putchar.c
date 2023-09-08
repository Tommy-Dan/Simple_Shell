#include "main.h"

/**
 * _putchar - prints character by character
 * @c: character
 * Return: Returns a charater
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
