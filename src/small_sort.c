/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:37:06 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/16 12:33:42 by anoviedo         ###   ########.fr       */
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

int	move_smallest_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	cont;

	cont = 0;
	pos = find_smallest(a);
	cont += move_to_top(a, pos);
	pb(a, b);
	write(1, "pb\n", 3);
	cont++;
	return (cont);
}

int	small_sort(t_stack *a, t_stack *b)
{
	int	cont;

	cont = 0;
	if (a->size <= 3 || a->size > 5)
		return (0);
	if (a->size == 4)
	{
		pb(a, b);
		write(1, "pb\n", 3);
		cont += tiny_sort(a);
		pa(a, b);
		write(1, "pa\n", 3);
		return (cont += 2);
	}
	cont += move_smallest_to_b(a, b);
	cont += move_smallest_to_b(a, b);
	cont += tiny_sort(a);
	pa(a, b);
	write(1, "pa\n", 3);
	cont++;
	pa(a, b);
	write(1, "pa\n", 3);
	cont++;
	return (cont);
}
