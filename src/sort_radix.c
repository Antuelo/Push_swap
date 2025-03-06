/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:27:09 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/06 22:47:32 by anoviedo         ###   ########.fr       */
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

void	counterbits(t_stack *a, int bit_position, int *one)
{
	t_node	*tmp;

	*one = 0;
	tmp = a->top;
	while (tmp)
	{
		if (((tmp->value >> bit_position) & 1))
			*one += 1;
		tmp = tmp->next;
	}
}

void	make_desicion(t_stack *a, t_stack *b, int size, int i)
{
	int	j;
	int	one_counter;

	j = 0;
	counterbits(a, i, &one_counter);
	while (j < size && one_counter > 0)
	{
		if (((a->top->value >> i) & 1))
		{
			rotate(a);
			write(1, "ra\n", 3);
			one_counter--;
		}
		else
		{
			pb(a, b);
			write(1, "pb\n", 3);
		}
		j++;
	}
}

int	max_bits(t_stack *a)
{
	int		max;
	t_node	*tmp;
	int		bits;

	max = 0;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int	pos_bit;
	int	maxbits;
	int	size;

	pos_bit = 0;
	maxbits = max_bits(a);
	while (pos_bit < maxbits)
	{
		size = a->size;
		make_desicion(a, b, size, pos_bit);
		empy_b(a, b);
		pos_bit++;
	}
}
