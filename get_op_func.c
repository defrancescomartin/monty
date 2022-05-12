#include "monty.h"

/**
 * get_op_func - match the opcode with corresponding function
 *
 * @op_code: opcode to match
 *
 * Return: pointer to corresponding function
 */
void (*get_op_func(char *op_code))(stack_t**, unsigned int)
{
	instruction_t op_fun[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{"sub", sub_stack},
		{"div", div_stack},
		{"mul", mul_stack},
		{"mod", mod_stack},
		{"pchar", pchar_stack},
		{"pstr", pstr_stack},
		{"rotl", rotl_stack},
		{"rotr", rotr_stack},
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
