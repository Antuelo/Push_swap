/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:27:21 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/06 17:52:42 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* sacar de B, para PONER en A*/

void	pa(t_stack *a, t_stack *b)
{
	int		value;
	int		error;

	error = 0;
	value = pop(b);
	if (error)
		return ;
	push(a, value);
}

/* sacar de A, para PONER en B */

void	pb(t_stack *a, t_stack *b)
{
	int		value;
	int		error;

	error = 0;
	value = pop(a);
	if (error)
		return ;
	push(b, value);
}

/* busca duplicados */

int	has_duplicate(t_stack *stack)
{
	t_node		*current;
	t_node		*checker;

	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (checker->value == current->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
