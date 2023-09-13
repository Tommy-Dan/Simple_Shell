#include "main.h"




/**
 * dup_chars - duplicates characters
 * @pathstr: PATH string
 * @start: start index
 * @stop: stop index
 * Return: pointer to the new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buffer[2024];
	int i = 0, j = 0;

	for (j = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buffer[j++] = pathstr[i];
	buffer[j] = 0;
	return (buffer);
}


/**
 * fork_cmd - forks a an exec thread to run cmd
 * @path: cmd path
 * @argv: an array argument vector
 * @envp: an array of environ
 * Return: Returns nothing
 */
void fork_cmd(const char *path, const char *argv[], char *const envp[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(path, (char *const *)argv, envp) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		wait(&status);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			if (exit_status == 126)
				fprintf(stderr, "Permission denied\n");
		}
	}
}
