#include "main.h"



/**
 * main - entry point
 * @argc: argument counts
 * @argv: argument vector pointer
 * @envp: environment pointer
 * Return: Returns (1) otherwise (0)
 */
int main(int argc, char *argv[], char *envp[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <command>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	const char *path = find_path(getenv("PATH"), argv[1]);

	if (path)
	{
		const char *cmd_argv[] = {path, NULL};

		fork_cmd(path, cmd_argv, envp);
		free((void *)path);
	}
	else
	{
		fprintf(stderr, "Command not found: %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
