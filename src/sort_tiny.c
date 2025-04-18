/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:06:31 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 22:38:32 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	first_case(t_stack *stack, int f, int s, int t)
{
	if (f > s && f < t)
	{
		swap(stack);
		write(1, "sa\n", 3);
		return (1);
	}
	if (f > s && s > t)
	{
		swap(stack);
		write(1, "sa\n", 3);
		reverotate(stack);
		write(1, "rra\n", 4);
		return (1);
	}
	if (f < s && s > t && f > t)
	{
		reverotate(stack);
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}

void	second_case(t_stack *stack, int f, int s, int t)
{
	if (f < s && s > t && f < t)
	{
		reverotate(stack);
		write(1, "rra\n", 4);
		swap(stack);
		write(1, "sa\n", 3);
	}
	if (f > s && s < t)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
}

void	tiny_sort(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
		{
			swap(stack_a);
			write(1, "sa\n", 3);
		}
		return ;
	}
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first < second && second < third)
		return ;
	if (!first_case(stack_a, first, second, third))
		second_case(stack_a, first, second, third);
	return ;
}
