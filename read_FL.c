#include "monty.h"

static int num_arg;

/**
 * read_FL - A function to read the file lines
 * @fname: The filename
 * @stack: stack
 */
void read_FL(char *fname, stack_t **stack)
{
	size_t length = 0;
	ssize_t readline = 0;
	char *operational_code = NULL, *lines = NULL;
	int line_count = 1;
	FILE *file;
	instruct_handler handler;


	/* open the file */
	file = fopen(fname, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
	/*read the lines*/

	lines = NULL;
	while ((readline = getline(&lines, &length, file)) != -1)
	{
		operational_code = interpret_line(line_count, lines);
		if (operational_code == NULL || operational_code[0] == '#')
		{
			line_count++;
			continue;
		}
		/*get the function related to the operational_code*/
		handler = find_opcode_handler(operational_code);
		if (handler == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_count, operational_code);
			exit(EXIT_FAILURE);
		}
		handler(stack, line_count);
		line_count++;
	}
	free(lines);
	fclose(file);
}
/**
 * interpret_line - parse the line
 * @linenum: linenum
 * @lines: line
 *
 * Return: operational_code or NULL
 */
char *interpret_line(int linenum, char *lines)
{
	char *operational_code = NULL;
	char *args = NULL;

	/*start by tokenize the string to get the operational_code*/
	operational_code = strtok(lines, " \n");
	if (operational_code == NULL)
		return (NULL);

	if (strcmp(operational_code, "push") == 0)
	{
		args = strtok(NULL, " \n");
		if (args != NULL && is_integer(args))
		{
			num_arg = atoi(args);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", linenum);
			exit(EXIT_FAILURE);
		}
	}
	return (operational_code);
}
/**
 * return_arg - return the arg variable
 * Return: arg value
 */

int return_arg(void)
{
	return (num_arg);
}
