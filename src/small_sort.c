/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:01:48 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/11 13:34:16 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_biggest(t_stack *a)
{
	t_node	*current;
	int		biggest;
	int		pos;
	int		i;

	biggest = a->top->value;
	current = a->top;
	pos = 0;
	i = 0;
	while (current)
	{
		if (current->value > biggest)
		{
			biggest = current->value;
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
	if (pos <= a->size)
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

int	move_biggest_to_b(t_stack *a, t_stack *b)
{
	int	pos;
	int	cont;

	cont = 0;
	pos = find_biggest(a);
	cont += move_to_top(a, pos);
	push(b, pop(a));
	write(1, "pb\n", 3);
	cont++;
	return (cont);
}

int	small_sort(t_stack *a, t_stack *b)
{
	int	cont;

	cont = 0;
	if (a->size != 5)
		return (0);
	cont += move_biggest_to_b(a, b);
	cont += move_biggest_to_b(a, b);
	rotate(b);
	write(1, "rb\n", 3);
	cont++;
	cont += tiny_sort(a);
	if (b->top)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		cont++;
	}
	if (b->top)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		cont++;
	}
	return (cont);
}
