# include "shell.h"

/**
  *_strncmp- function that compares two strings
  *@s1: input string to be compared
  *@s2: input string to be compared
  *@n: maximum number of characters to compare
  *Return: 0 if strings are equal up to n
  */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t c;

	for (c = 0; (s1[c] != '\0' || s2[c] != '\0') && c < n; c++)
	{
		if (s1[c] != s2[c])
			return (s1[c] - s2[c]);
	}
	return (0);
}

/**
 *_strcmp- function that compares two strings
 *@s1: input string
 *@s2: input string
 *Return: always 0
 */
int _strcmp(char *s1, char *s2)
{
	int p;

	for (p = 0; s1[p] != '\0' || s2[p] != '\0'; p++)
	{
		if (s1[p] != s2[p])
			return (s1[p] - s2[p]);
	}
	return (0);
}

/**
 *_strlen- returns the length of a string
 *@s: a string variable
 *Return: 0
 */
int _strlen(char *s)
{
	int n;

	for (n = 0; s[n] != '\0'; n++)
		;

	return (n);
}
