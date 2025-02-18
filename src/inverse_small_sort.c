/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_small_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:15:42 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/18 17:29:29 by anoviedo         ###   ########.fr       */
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

int	move_to_top(t_stack *a, int pos)
{
	int	cont;

	cont = 0;
	if (pos == 0)
		return (0);
	if (pos <= a->size / 2)
	{
		while (pos--)
		{
			rotate(a);
			write(1, "ra\n", 3);
			cont++;
		}
	}
	else
	{
		while (pos++ < a->size)
		{
			reverotate(a);
			write(1, "rra\n", 4);
			cont++;
		}
	}
	return (cont);
}

int	move_largest_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	cont;

	cont = 0;
	pos = find_largest(a);
	cont += move_to_top(a, pos);
	pb(a, b);
	write(1, "pb\n", 3);
	cont++;
	return (cont);
}

int	inverse_small_sort(t_stack *a, t_stack *b)
{
	int	cont;

	cont = 0;
	if (a->size == 5)
		cont += move_largest_to_b(a, b);
	cont += move_largest_to_b(a, b);
	cont += inverse_tiny_sort(a);
	pa(a, b);
	write(1, "pa\n", 3);
	cont++;
	if (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		cont++;
	}
	return (cont);
}
