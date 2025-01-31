/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:27:21 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/30 15:55:00 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int		value;

	if (b->top == NULL)
		return ;
	value = pop(b);
	push(a, value);
}

void	pb(t_stack *a, t_stack *b)
{
	int		value;

	if (a->top == NULL)
		return ;
	value = pop(a);
	push(b, value);
}

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
