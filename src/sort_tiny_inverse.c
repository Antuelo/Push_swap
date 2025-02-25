/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny_inverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:32:31 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 22:45:43 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	first_inverse_case(t_stack *a, t_stack *b, t_values vals)
{
	if (vals.f < vals.s && vals.s < vals.t && vals.f < vals.t)
	{
		swap(b);
		write(1, "sb\npa\nsb\npb\nsb\n", 15);
		pa(a, b);
		swap(b);
		pb(a, b);
		swap(b);
		return (1);
	}
	if (vals.f > vals.s && vals.s < vals.t && vals.f < vals.t)
	{
		pa(a, b);
		write(1, "pa\nsb\npb\nsb\n", 12);
		swap(b);
		pb(a, b);
		swap(b);
		return (1);
	}
	return (0);
}

void	second_inverse_case(t_stack *a, t_stack *b, t_values vals)
{
	if (vals.f < vals.s && vals.f > vals.t && vals.s > vals.t)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	if (vals.f > vals.s && vals.s < vals.t && vals.f > vals.t)
	{
		write(1, "pa\nsb\npb\n", 9);
		pa(a, b);
		swap(b);
		pb(a, b);
	}
	if (vals.f < vals.s && vals.s > vals.t)
	{
		swap(b);
		write(1, "sb\n", 3);
		pa(a, b);
		write(1, "pa\n", 3);
		swap(b);
		write(1, "sb\n", 3);
		pb(a, b);
		write(1, "pb\n", 3);
	}
}

void	sort_tiny_inverse(t_stack *a, t_stack *b)
{
	t_values	vals;

	if (b->size == 2)
	{
		if (b->top->value < b->top->next->value)
		{
			swap(a);
			write(1, "sb\n", 3);
		}
		return ;
	}
	vals.f = b->top->value;
	vals.s = b->top->next->value;
	vals.t = b->top->next->next->value;
	if (vals.f > vals.s && vals.s > vals.t)
		return ;
	if (!first_inverse_case(a, b, vals))
		second_inverse_case(a, b, vals);
}
