#include "shell.h"

/**
 * free_array - frees an array
 * @args: an array of pointers.
 */

void free_array(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
