#include "monty.h"

/**
 * get_op_func -gets opcode to corresponding function
 *
 * @op_code: type of opcode to match
 *
 * Return: pointer to corresponding function
 */
void (*get_op_func(char *op_code))(stack_t**, unsigned int)
{
	instruction_t op_fun[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add_stack},
		{"nop", nop_stack},
		{NULL, NULL}
	};

	int i = 0;

	while (op_fun[i].opcode != NULL)
	{
		if ((strcmp(op_fun[i].opcode, op_code)) == 0)
			return (op_fun[i].f);
		i++;
	}
	return (NULL);
}
