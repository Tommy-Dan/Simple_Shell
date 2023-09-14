#include "shell.h"




/**
 *string_token- function that tokenize a given string
 *@s: the input string to be tokenized
 *@delim: the character used to tokenize
 *Return: the tokens
 */
char **string_token(char *s, char *delim)
{
	char *token, *tmp, **arr;
	int len;

	tmp = strdup(s);
	if (tmp == NULL)
		return (NULL);
	token = strtok(tmp, delim);
	len = 0;
	while (token != NULL)
	{
		++len;
		token = strtok(NULL, delim);
	}
	/* Let allocate memory for 'len' of  words */
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
	{
		free(tmp);
		return (NULL);
	}
	/* Let copy each tokens into arr */
	token = strtok(s, delim);
	len = 0;
	while (token != NULL)
	{
		arr[len] = strdup(token);
		if (arr[len] == NULL)
		{
			/* If memeory allocation fail free previous allocated memory*/
			free_array(arr);
			return (NULL);
		}
		token = strtok(NULL, delim);
		++len;
	}
	free(tmp);
	arr[len] = NULL;
	return (arr);
}
