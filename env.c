#include "shell.h"

/**
  *handleEnv- function that prints the environ variables
  *@command: input command from the user
  *Return: the enironment variables
  */

int handleEnv(char **command)
{
	char **env;

	env = environ;
	if (command[1] != NULL)
		return (1);
	while (*env != NULL)
	{
		printStr(*env);
		env++;
	}
	putchar('\n');
	return (0);
}
