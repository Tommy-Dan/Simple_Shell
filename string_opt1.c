#include "main.h"



/**
 * _strlen - returns the length of a string
 * @str: string length to check
 * Return: Returns length of string
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}


/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: Returns a pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int i, length;
	char *rtn;

	if (str == NULL)
		return (NULL);

	length = 0;
	rtn = NULL;

	while (str[length] != '\0')
		length++;
	rtn = (char *)malloc(sizeof(char) * (length + 1));
	if (rtn == NULL)
	{
		perror("memory allocation failed");
		return (NULL);
	}
	for (i = 0; i < length; i++)
		rtn[i] = str[length - i - 1];
	rtn[length] = '\0';
	free(rtn);
	return (rtn);
}


/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@num: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, const char *src, size_t num)
{
	char *d = dest;

	while (num > 0 && *src)
	{
		*d++ = *src++;
		num--;
	}
	while (num > 0)
	{
		*d++ = '\0';
		num--;
	}
	return (dest);
}


/**
 **_strncmp - compare number of string
 *@str1: the str1 string to be compare
 *@str2: string compare
 *@num: the amount of characters to be compare
 *Return: Returns string
 */
int _strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		if (str1[i] == '\0')
			break;
	}
	return (0);
}


/**
 * _strchr - locates a character in a string
 * @str: the string to be parsed
 * @c: the caharacter to look for
 * Return: Returns str a point the memory area
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	}
	while (*str++ != '\0');
	return (NULL);
}
