#include "main.h"


/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: Returns (1) onsuccess otherwise (-1) on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _printstr - prints an input string
 * @str: string to be printed
 * Return: Returns nothing
 */
void _printstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}


/**
 * _strcpy - Copies a null-terminated string from src to dest.
 * @dest: destination buffer.
 * @src: source string.
 * Return: Returns a pointer to the destination.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0' && i < DEST_SIZE - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * _strcat - concatenate two strings
 * @src: source file
 * @dest: destination file
 * Return: Returns a pointer to destination file
 */
char *_strcat(char *dest, char *src)
{
	char *rtn = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rtn);
}
