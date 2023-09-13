# include "shell.h"

/**
 *_strncat- concatenates two strings
 *@dest: destination of string
 *@src: source of string
 *@n: number of bytes to append
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int idx, m;

	idx = 0;
	while (dest[idx] != '\0')
	{
		idx++;
	}
	for (m = 0; src[m] != '\0' && n > 0; m++, m--, idx++)
	{
		dest[idx] = src[m];
	}
	return (dest);
}

/**
 *_strncpy- copies n bytes of a string
 *@dest: destination of string
 *@src: source of string
 *@n: number of bytes to copy
 *Return: always 0
 */
char *_strncpy(char *dest, char *src, int n)
{
	int c;

	for (c = 0; c < n && src[c] != '\0'; c++)
		dest[c] = src[c];

	for (; n > c; c++)
		dest[c] = '\0';

	return (dest);
}

/**
 *_strcpy- copies the string pointed to by src
 *@dest: destination
 *@src: source
 *Return: 0
 */
char *_strcpy(char *dest, char *src)
{
	int len, m;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}

	for (m = 0; m < len; m++)
	{
		dest[m] = src[m];
	}
	dest[m] = '\0';

	return (dest);
}

/**
 *_strcat- function that concatenates two strings
 *@dest: destination of the string
 *@src: source of the string
 *Return: 0
 */
char *_strcat(char *dest, char *src)
{
	int i, n;

	i = 0;
	while (dest[i] != '\0')
		i++;

	for (n = 0; src[n] != '\0'; n++)
	{
		dest[i] = src[n];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
