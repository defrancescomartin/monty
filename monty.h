#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* declaration of global variable */
extern int number;



/* declaration of data structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;




/* getop func */
void (*get_op_func(char *op_code))(stack_t**, unsigned int);



 /* declaration of functions prototipes */
void push_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)));
void pall_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)));
void pint_stack(stack_t **top, unsigned int line_number);
void pop_stack(stack_t **top, unsigned int line_number);
void swap_stack(stack_t **top, unsigned int line_number);
void add_stack(stack_t **top, unsigned int line_number);
void nop_stack(stack_t **top __attribute__((unused)),
	       unsigned int line_number __attribute__((unused)));
void sub_stack(stack_t **top, unsigned int line_number);
void free_stack(stack_t **top);
void div_stack(stack_t **top, unsigned int line_number);
void mul_stack(stack_t **top, unsigned int line_number);
void mod_stack(stack_t **top, unsigned int line_number);
void pchar_stack(stack_t **top, unsigned int line_number);
void pstr_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)));
void rotl_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)));
void rotr_stack(stack_t **top,
		unsigned int line_number __attribute__((unused)));
void push_queue(stack_t **top,
		unsigned int line_number __attribute__((unused)));
int is_comment(char *s);
int is_number(char *s);

#endif /* MONTY_H */
