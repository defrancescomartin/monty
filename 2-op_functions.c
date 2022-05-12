#include "monty.h"

/* push_queue, is_number and is_comment functions used in main.c */

/**
 * push_queue - Function that enqueue a node at the rear of a stack_t queue.
 *
 * @top: Head of the linked list
 * @line_number: Line count
 *
 */
void push_queue(stack_t **top,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *new_queue;
	stack_t *ptr = *top;

	new_queue = malloc(sizeof(stack_t));
	if (new_queue == NULL && *top != NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_stack(&(*top));
		exit(EXIT_FAILURE);
	}
	else if (new_queue == NULL && *top == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/* Node creation */
	new_queue->n = number;
	new_queue->prev = NULL;
	new_queue->next = NULL;

	/* EDGE case: list is empty */
	if (*top == NULL)
		*top = new_queue;
	else
	{
/* Iterate *ptr until the last node of queue */
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_queue;
		new_queue->prev = ptr;
	}
}

/**
 * is_comment - check if the first char is a comment #
 *
 * @s: pointr to char (string)
 * Return: 0 on succes 1 if it fails.
 */
int is_comment(char *s)
{
	if (s[0] == '#')
		return (1);
	else
		return (0);
}

/**
 * is_number - check if an string is number
 *
 * @s: pointr to char (string)
 * Return: 0 on succes 1 if it fails.
 */
int is_number(char *s)
{
	if (s[0] == '-')
		s++;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			s++;

		else
		{
			return (1);
		}
	}
	return (0);
}
