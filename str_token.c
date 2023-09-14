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
	token = strtok(tmp, delim);
	len = 0;
	while (token != NULL)
	{
		++len;
		token = strtok(NULL, delim);
	}

	/* Allocate memory for 'len' words */
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);

	/* Copy each token into arr */
	token = strtok(s, delim);
	len = 0;
	while (token != NULL)
	{
		arr[len] = strdup(token);
		token = strtok(NULL, delim);
		++len;
	}
	free(tmp);
	arr[len] = NULL;
	return (arr);
}