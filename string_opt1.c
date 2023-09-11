#include "main.h"




/**
 * str_split1 - splits a string into words.
 * @str: the input string
 * @delim: the delimeter string
 * Return: Returns a pointer to an array of strings, or NULL on failure
 */
char **str_split1(char *str, char *delim)
{
	int i, j, k, l;
	int wordcounts = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	if (!delim)
		delim = " ";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], delim) &&
			(is_delim(str[i + 1], delim) || str[i + 1] == '\0'))
			wordcounts++;
	}
	if (wordcounts == 0)
		return (NULL);
	s = (char **)malloc((wordcounts + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < wordcounts; j++)
	{
		while (is_delim(str[i], delim))
			i++;
		k = 0;
		while (!is_delim(str[i + k], delim) && str[i + k] != '\0')
			k++;
		s[j] = (char *)malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
			{
				free(s[k]);
			}
			free(s);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			s[j][l] = str[i++];
		s[j][l] = '\0';
	}
	s[j] = NULL;
	return (s);
}


/**
 * str_split2 - splits a string into words
 * @str: the input string
 * @delim: the delimeter
 * Return: Returns a pointer to an array of strings, or NULL on failure
 */
char **str_split2(char *str, char delim)
{
	int i, j, k, m;
	int wordcounts = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delim && str[i + 1] == delim) ||
				(str[i] != delim && !str[i + 1]) ||
				str[i + 1] == delim)
			wordcounts++;
	if (wordcounts == 0)
		return (NULL);
	s = (char **)malloc((wordcounts + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < wordcounts; j++)
	{
		while (str[i] == delim && str[i] != delim)
			i++;
		k = 0;
		while (str[i + k] != delim && str[i + k] && str[i + k] != delim)
			k++;
		s[j] = (char *)malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
			{
				free(s[k]);
			}
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
