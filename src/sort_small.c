/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:37:06 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 22:45:00 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_smallest(t_stack *a)
{
	t_node	*current;
	int		smallest;
	int		pos;
	int		i;

	smallest = a->top->value;
	current = a->top;
	pos = 0;
	i = 0;
	while (current)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void	move_to_top(t_stack *a, int pos)
{
	if (pos == 0)
		return ;
	if (pos <= a->size / 2)
	{
		while (pos--)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (pos++ < a->size)
		{
			reverotate(a);
			write(1, "rra\n", 4);
		}
	}
}

void	move_smallest_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_smallest(a);
	move_to_top(a, pos);
	pb(a, b);
	write(1, "pb\n", 3);
}

void	small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 5)
		move_smallest_to_b(a, b);
	move_smallest_to_b(a, b);
	tiny_sort(a);
	pa(a, b);
	write(1, "pa\n", 3);
	if (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
	}
}
