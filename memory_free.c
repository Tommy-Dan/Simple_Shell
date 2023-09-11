#include "main.h"


/**
 * free_str_array - freeing all array pointers
 * @arr: an array pointers to be free
 * Return: Returns nothing
 */

void free_str_array(char **arr)
{
	if (arr)
	{
		for (int i = 0; arr[i] != NULL; i++)
			free(arr[i]);
		free(arr);
	}
}
