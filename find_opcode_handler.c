#include "monty.h"

/**
 * find_opcode_handler - get associate function to the operational_code
 * @operational_code: string
 *
 * Return: appropriate function or NULL
 */

instruct_handler find_opcode_handler(char *operational_code)
{
	int idx = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"div", divide},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	while (instructions[idx].f != NULL)
	{
		if (strcmp(instructions[idx].opcode, operational_code) == 0)
		{
			return (instructions[idx].f);
		}
		idx++;
	}
	return (NULL);
}
