#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the int converted from the string
 */

int _atoi(char *s)
{
	int i, m, n, len, p, q;

	i = 0;
	m = 0;
	n = 0;
	len = 0;
	p = 0;
	q = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && p == 0)
	{
		if (s[i] == '-')
			++m;

		if (s[i] >= '0' && s[i] <= '9')
		{
			q = s[i] - '0';
			if (m % 2)
				q = -q;
			n = n * 10 + q;
			p = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			p = 0;
		}
		i++;
	}

	if (p == 0)
		return (0);

	return (n);
}
