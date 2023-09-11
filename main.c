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
		printf("Result 1:\n");
		_printstr("Result 1: \n");

		for (i = 0; result1[i] != NULL; i++)
			printf("%s\n", result1[i]);
	}
	if (result2)
	{
		printf("Result 2:\n");
		_printstr("Result 2: \n");

		for (i = 0; result2[i] != NULL; i++)
			printf("%s\n", result2[i]);
	}
	free_str_array(result1);
	free_str_array(result2);

	return (0);
}
