/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mysort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:15 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/20 08:24:50 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_lower_half_to_b(t_stack *a, t_stack *b, int median)
{
	int	count;
	int	pushed;

	count = 0;
	pushed = 0;
	while (pushed != 2)
	{
		if (a->top->value < median)
		{
			pb(a, b);
			write(1, "pb\n", 3);
			count++;
			pushed++;
		}
		else
		{
			rotate(a);
			write(1, "ra\n", 3);
			count++;
		}
	}
	return (count);
}

int	quicksort(t_stack *a, t_stack *b)
{
	int	median;
	int	count;

	count = 0;
	if (a->size > 5)
	{
		median = findmedian(a);
		count += push_lower_half_to_b(a, b, median);
		if (b->size > 0)
			count += sort_inverse_b(b);
		count += quicksort(a, b);
	}
	else
		small_sort(a, b);
	while (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		count++;
	}
	return (count);
}
