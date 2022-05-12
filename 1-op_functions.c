#include "monty.h"

/* add, nop, free, sub functions */

/**
 * add_stack - adds the top two elements of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void add_stack(stack_t **top, unsigned int line_number)
{
	int sum = 0;
	stack_t *tmp_node = *top;

	/* border case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		sum = (*top)->n + (*top)->next->n;
		(*top) = (*top)->next;
		(*top)->n = sum;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}

/**
 * nop_stack - does not do anything
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void nop_stack(stack_t **top __attribute__((unused)),
	       unsigned int line_number __attribute__((unused)))
{
/* what are you looking for here? cya @ event space tomorrow o/ */
}

/**
 * free_stack - frees the memory
 *
 * @top: head of the linked list
 *
 */
void free_stack(stack_t **top)
{
	if (*top == NULL || top == NULL)
	{
		return;
	}
	while ((*top)->next != NULL)
	{
		*top = (*top)->next;
		free((*top)->prev);
	}
	free(*top);
}

/**
 * sub_stack - function that subtracts the top two elements of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void sub_stack(stack_t **top, unsigned int line_number)
{
	int sub = 0;
	stack_t *tmp_node = *top;

	/* border case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		sub = (*top)->next->n - (*top)->n;
		(*top) = (*top)->next;
		(*top)->n = sub;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}
