#include "shell.h"

/**
 *validate- check whether a given command exists and then execute it
 *@args:  array of strings containing the command and its arguments
 *@line: buffer for the input strings
 *Return: always 0 if successful
 */
int validate(char **args, char *line)
{
	int cmd_status;
	char *path;
	struct stat status;

	if (stat(args[0], &status) == 0)
		cmd_status = execute_cmd(args, line);
	else
	{
		path = handle_path(args[0]);
		if (path != NULL)
		{
			free(args[0]);
			args[0] = path;
			cmd_status = execute_cmd(args, line);
		}
		else
		{
			free_array(args);
			return (127);
		}
	}
	free_array(args);
	return (cmd_status);
}

/**
 *execute_cmd- function that execute a command
 *@args: array of strings containing the command and its arguments
 *@line: buffer for the input strings
 *Return: always 0 if successful
 */

int execute_cmd(char **args, __attribute__((unused)) char *line)
{
	int st;

	st = 0;
	switch (fork())
	{
		case -1:
			perror("Error\n");
			break;
		case 0:
			execve(args[0], args, environ);
			exit(0);
		default:
			wait(NULL);
			break;
	}
	return (st);
}
