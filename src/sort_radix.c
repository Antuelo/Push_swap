/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:27:09 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/20 18:31:14 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	empy_b(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	while (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		count++;
	}
	return (count);
}

int	make_desicion(t_stack *a, t_stack *b, int size, int i)
{
	int		j;
	int		count;

	j = 0;
	count = 0;
	while (j < size)
	{
		if (!((a->top->value >> i) & 1))
		{
			pb(a, b);
			write(1, "pb\n", 3);
			count += 2;
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
			count++;
		}
		j++;
	}
	return (count);
}

int	sort_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	count;

	i = 0;
	count = 0;
	while (its_ordered(a))
	{
		size = a->size;
		count = make_desicion(a, b, size, i);
		count += empy_b(a, b);
		i++;
	}
	return (count);
}
