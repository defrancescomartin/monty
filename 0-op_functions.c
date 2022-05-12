#include "monty.h"

/* push, pall, pint, pop, swap functions*/

/**
 * push_stack - pushes a node at the top of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void push_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *new_top;

	new_top = malloc(sizeof(stack_t));
	if (new_top == NULL && *top != NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_stack(&(*top));
		exit(EXIT_FAILURE);
	}
	else if (new_top == NULL && *top == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_top->n = number;
	new_top->prev = NULL;
	new_top->next = NULL;
	if (*top == NULL)
		*top = new_top;
	else
	{
		new_top->next = *top;
		(*top)->prev = new_top;
		*top = new_top;
	}
}

/**
 * pall_stack - prints all the values on the stack_t stack
 * starting form the top of the stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void pall_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *top;

	/* check conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
		return;

	else
	{
		while (ptr != NULL)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}

/**
 * pint_stack - funtion that prints the value at the top of a stack_t stack
 * followed by a new line
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void pint_stack(stack_t **top, unsigned int line_number)
{
	/* check conditions if stack is empty or does not exist */
	if (*top == NULL)
	{
		dprintf(2, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*top)->n);
	}
}

/**
 * pop_stack - removes the top element of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void pop_stack(stack_t **top, unsigned int line_number)
{
	stack_t *ptr = *top;

	/* check conditions if stack is empty or does not exist */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* border case: single element in stack */
		if ((*top)->next == NULL)
		{
			*top = (*top)->next;
			free(ptr);
		}
		else
		{
			*top = (*top)->next;
			free(ptr);
			(*top)->prev = NULL;
		}
	}
}

/**
 * swap_stack - function that swaps the top two elementes of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void swap_stack(stack_t **top, unsigned int line_number)
{
	/* border case: If the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* border case: stack has two elements */
		if ((*top)->next->next == NULL)
		{
			(*top)->prev = (*top)->next;
			(*top)->next->next = (*top);
			(*top)->next->prev = NULL;
			(*top)->next = NULL;
			*top = (*top)->prev;
		}
		/* border case: stack has more than two elements */
		else
		{
			(*top)->prev = (*top)->next;
			(*top)->next = (*top)->next->next;
			(*top)->next->prev = *top;
			(*top)->prev->next = *top;
			(*top)->prev->prev = NULL;
			(*top) = (*top)->prev;
		}
	}
}
