#include "monty.h"

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

	/* border case: if the stack contains less than two elements */
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
/*hey! nothing to see here ;) cya at my speaker tomorrow */
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
 * sub_stack - subtracts the top two elements of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void sub_stack(stack_t **top, unsigned int line_number)
{
	int sub = 0;
	stack_t *tmp_node = *top;

	/* border case: if the stack contains less than two elements */
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

/**
 * div_stack - divides the top two elements of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void div_stack(stack_t **top, unsigned int line_number)
{
	int div = 0;
	stack_t *tmp_node = *top;

	/* border case: if the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_stack(&(*top));
		exit(EXIT_FAILURE);
	}
	else
	{
		div = (*top)->next->n / (*top)->n;
		(*top) = (*top)->next;
		(*top)->n = div;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}
