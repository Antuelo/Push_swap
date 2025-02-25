/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_inverse_small_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:15:42 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 22:44:03 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_largest(t_stack *a)
{
	t_node	*current;
	int		largest;
	int		pos;
	int		i;

	largest = a->top->value;
	current = a->top;
	pos = 0;
	i = 0;
	while (current)
	{
		if (current->value > largest)
		{
			largest = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void	move_to_top_inverse(t_stack *a, int pos)
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

void	move_largest_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_largest(a);
	move_to_top_inverse(a, pos);
	pb(a, b);
	write(1, "pb\n", 3);
}

void	sort_inverse_small_sort(t_stack *a, t_stack *b)
{
	if (a->size == 5)
		move_largest_to_b(a, b);
	if (a->size >= 4)
		move_largest_to_b(a, b);
	if (a->size <= 3)
		sort_tiny_inverse(a, b);
	pa(a, b);
	write(1, "pa\n", 3);
	if (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
	}
}
