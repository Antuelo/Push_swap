/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_tiny_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:33:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/17 18:33:44 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	first_inverse_case(t_stack *stack, int f, int s, int t)
{
	if (f < s && f > t)
	{
		swap(stack);
		write(1, "sb\n", 3);
		return (1);
	}
	if (f < s && s < t)
	{
		swap(stack);
		write(1, "sb\n", 3);
		reverotate(stack);
		write(1, "rrb\n", 4);
		return (2);
	}
	if (f > s && s < t && f < t)
	{
		reverotate(stack);
		write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	second_inverse_case(t_stack *stack, int f, int s, int t)
{
	if (f > s && s < t && f > t)
	{
		swap(stack);
		write(1, "sb\n", 3);
		rotate(stack);
		write(1, "rb\n", 3);
		return (2);
	}
	if (f < s && s > t && f < t)
	{
		reverotate(stack);
		write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	inverse_tiny_sort(t_stack *stack_b)
{
	int	first;
	int	second;
	int	third;
	int	cont;

	cont = 0;
	if (stack_b->size == 2)
	{
		if (stack_b->top->value < stack_b->top->next->value)
		{
			swap(stack_b);
			write(1, "sb\n", 3);
			return (1);
		}
		return (0);
	}
	first = stack_b->top->value;
	second = stack_b->top->next->value;
	third = stack_b->top->next->next->value;
	if (first > second && second > third)
		return (0);
	cont = first_inverse_case(stack_b, first, second, third);
	if (cont == 0)
		cont = second_inverse_case(stack_b, first, second, third);
	return (cont);
}
