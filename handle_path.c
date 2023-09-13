#include "shell.h"

/**
  *handle_path- function that handles full path
  *@args: array that cotains the command
  *Return: always 0 if successful
  */

char *handle_path(char *args)
{
	char path[BUFSIZ];
	char **path_arr, *tmp;
	int i;
	struct stat status;

	tmp = getenv("PATH");
	_strcpy(path, tmp);
	path_arr = string_token(path, ":");
	for (i = 0; path_arr[i]; i++)
	{
		tmp = malloc(sizeof(char) * (_strlen(path_arr[i]) + _strlen(args) + 2));
		if (tmp == NULL)
		{
			perror("Memory not Allocated");
			break;
		}
		_strcpy(tmp, path_arr[i]);
		_strcat(tmp, "/");
		_strcat(tmp, args);

		if (stat(tmp, &status) == 0)
		{
			free_array(path_arr);
			return (tmp);
		}
		free(tmp);
	}
	free_array(path_arr);
	return (NULL);
}
