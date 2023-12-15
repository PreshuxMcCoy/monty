#include "monty.h"

/**
 * is_integer - Function to check if an argument is an integer
 * @str: string to check
 *
 * Return: 1 if number 0 if not
 */

int is_integer(char *str)
{
	int idx = 0;

	if (str == NULL)
		return (0);
	while (str[idx] != '\0')
	{
		if (str[0] == '-')
		{
			idx++;
			continue;
		}
		if (str[idx] < 48 || str[idx] > 57)
			return (0);
		idx++;
	}
	return (1);
}
