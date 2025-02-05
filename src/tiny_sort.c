/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:06:31 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/06 00:30:44 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	first_case(t_stack *stack, int f, int s, int t)
{
	int	moves;

	moves = 0;
	if (f > s && s < t && f < t)
	{
		swap(stack);
		write(1, "sa\n", 3);
		moves++;
	}
	else if (f > s && s > t)
	{
		swap(stack);
		write(1, "sa\n", 3);
		reverotate(stack);
		write(1, "rra\n", 4);
		moves += 2;
	}
	else if (f > s && s < t && f > t)
	{
		rotate(stack);
		write(1, "ra\n", 3);
		moves++;
	}
	return (moves);
}

int	second_case(t_stack *stack, int f, int s, int t)
{
	int	moves;

	moves = 0;
	if (f < s && s > t && f < t)
	{
		swap(stack);
		write(1, "sa\n", 3);
		rotate(stack);
		write(1, "ra\n", 3);
		moves += 2;
	}
	else if (f < s && s > t)
	{
		reverotate(stack);
		write(1, "rra\n", 4);
		moves++;
	}
	return (moves);
}

int	tiny_sort(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;
	int	moves;

	moves = 0;
	if (stack_a->size < 3)
		return (0);
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first < second && second < third)
		return (0);
	moves += first_case(stack_a, first, second, third);
	if (moves == 0)
		moves += second_case(stack_a, first, second, third);
	return (moves);
}

/*
int	first_case(t_stack *stack, int f, int s, int t)
{
	if (f > s && f < t)
	{
		swap(stack);
		write (1, "sa\n", 3);
		return (1);
	}
	if (f > s && s > t)
	{
		swap(stack);
		write (1, "sa\n", 3);
		reverotate(stack);
		write (1, "rra\n", 4);
		return (2);
	}
	if (f < s && s > t)
	{
		swap(stack);
		write (1, "sa\n", 3);
		rotate(stack);
		write (1, "ra\n", 3);
		return (2);
	}
	return (0);
}

int	second_case(t_stack *stack, int f, int s, int t)
{
	if (f < s && s > t)
	{
		reverotate(stack);
		write (1, "rra\n", 4);
		return (1);
	}
	if (f > s && s < t)
	{
		rotate(stack);
		write (1, "ra\n", 3);
		return (1);
	}
	return (0);
}

int	tiny_sort(t_stack *stack_a)
{
	int		first;
	int		second;
	int		third;
	int		cont;

	cont = 0;
	if (stack_a->size < 3)
		return (0);
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first < second && second < third)
		return (0);
	cont = first_case(stack_a, first, second, third);
	if (cont == 0)
		cont = second_case(stack_a, first, second, third);
	return (cont);
}
*/
