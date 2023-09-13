#include "shell.h"

/**
 * builtin - handles builtin
 * @args: commands
 * @line: line
 * @status: program status
 * Return: 0 if builtin is found, else 1
 *
 */

int builtin(char **args, char *line, int status)
{
	char *builtin_cmd[] = {"exit", "env", NULL};

	if (_strcmp(builtin_cmd[0], args[0]) == 0)
		return (ExitCommand(args, line, status));
	else if (_strcmp(builtin_cmd[1], args[0]) == 0)
		return (handleEnv(args));
	else
		return (1);
}
