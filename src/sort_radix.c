/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:27:09 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 22:07:08 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	empy_b(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
	}
}

void	make_desicion(t_stack *a, t_stack *b, int size, int i)
{
	int		j;

	j = 0;
	while (j < size)
	{
		if (!((a->top->value >> i) & 1))
		{
			pb(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		j++;
	}
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	i = 0;
	while (its_ordered(a))
	{
		size = a->size;
		make_desicion(a, b, size, i);
		empy_b(a, b);
		i++;
	}
}
