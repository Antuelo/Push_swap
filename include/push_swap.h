#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include "libft.h"

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
} t_stack;

void	create_stack (t_stack *stack);
void	push(t_stack *stack, int value);

#endif
