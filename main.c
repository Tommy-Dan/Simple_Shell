<<<<<<< HEAD
#include "main.h"


/**
 * main - entry point
 * Return: Returns (0) on success otherwise
 */
int main(void)
{
	char input1[] = "Hello, World! This is a test string";
	char input2[] = "This-is-another-test-string";
	char **result1, **result2;
	int i;

	result1 = str_split1(input1, " ,");
	result2 = str_split2(input2, '-');

	if (result1)
	{
		_printstr("Result 1: \n");

		for (i = 0; result1[i] != NULL; i++)
			printf("%s\n", result1[i]);
			_printstr("\n");
	}
	if (result2)
	{
		_printstr("Result 2: \n");

		for (i = 0; result2[i] != NULL; i++)
			printf("%s\n", result2[i]);
			_printstr("\n");
	}
	free_str_array(result1);
	free_str_array(result2);

	return (0);
=======
#include "shell.h"

/**
 * main - program stats.
 * Return: program status.
 */
int main(void)
{
	char *prompt;
	char *line = NULL, **token_arr;
	int int_mode = isatty(STDIN_FILENO);
	int exitStatus = 0;
	size_t size = 0;
	ssize_t nchars_read;

	while (1)
	{
		prompt = "T&M-SHELL:~$ ";
		if (int_mode == 1)
			printStr(prompt);
		nchars_read = getline(&line, &size, stdin);
		if (nchars_read == -1)
		{
			if (int_mode == 1)
				putchar('\n');
			break;
		}
		/*Remove the trailing newline character */
		if (line[nchars_read - 1] == '\n')
			line[nchars_read - 1] = '\0';

		token_arr = string_token(line, " \t");
		if (token_arr[0] == NULL)
		{
			free(token_arr);
			continue;
		}
		exitStatus = builtin(token_arr, line, exitStatus);
		if (exitStatus == 1)
			exitStatus = validate(token_arr, line);
		free_array(token_arr);
	}
	free(line);
	return (exitStatus);
>>>>>>> bdf403ee8d54eefcab8712453c5a5772e0f99779
}
