#include "monty.h"

/**
 * mul_stack - multiplies the two elements of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void mul_stack(stack_t **top, unsigned int line_number)
{
	int mul = 0;
	stack_t *tmp_node = *top;

	/* border case: if the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free(*top);
		exit(EXIT_FAILURE);
	}
	else
	{
		mul = (*top)->next->n * (*top)->n;
		(*top) = (*top)->next;
		(*top)->n = mul;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}

/**
 * mod_stack - computes rest of div of two elements of a stack_t stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void mod_stack(stack_t **top, unsigned int line_number)
{
	int mod = 0;
	stack_t *tmp_node = *top;

	/* border case: if the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*top)->next == NULL)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
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
		mod = (*top)->next->n % (*top)->n;
		(*top) = (*top)->next;
		(*top)->n = mod;
		(*top)->prev = NULL;
		free(tmp_node);
	}
}


/**
 * pchar_stack - prints the char at the top of the stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void pchar_stack(stack_t **top, unsigned int line_number)
{
	/* border case: if the stack contains less than two elements */
	if (*top == NULL || top == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*top)->n >= 65 && (*top)->n <= 90)
			printf("%c\n", (*top)->n);
		else if ((*top)->n >= 97 && (*top)->n <= 122)
			printf("%c\n", (*top)->n);
		else
		{
			dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
			free_stack(&(*top));
			exit(EXIT_FAILURE);
		}
	}
}


/**
 * pstr_stack - prints the string starting at the top of the stack
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void pstr_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *top;

	if (*top == NULL || top == NULL)
		printf("\n");

	else
	{
		while (ptr != NULL)
		{
			if ((ptr)->n >= 65 && (ptr)->n <= 90)
				printf("%c", (ptr)->n);
			else if ((ptr)->n >= 97 && (ptr)->n <= 122)
				printf("%c", (ptr)->n);
			else
				break;
			ptr = (ptr)->next;
		}
		printf("\n");
	}
}

/**
 * rotl _stack - rotates the stack to the top.
 *
 * @top: head of the linked list
 * @line_number: line count
 *
 */
void rotl_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)))
{
	stack_t *ptr = *top;
	/* border case: If the stack is empty */
	if (*top == NULL || top == NULL || (*top)->next == NULL)
		return;

	while (ptr->next != NULL)
		ptr = ptr->next;

	(*top) = (*top)->next;
	ptr->next = (*top)->prev;
	(*top)->prev->next = NULL;
	(*top)->prev->prev = ptr;
	(*top)->prev = NULL;
}
