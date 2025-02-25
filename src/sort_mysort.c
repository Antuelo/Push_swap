/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mysort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:15 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 22:13:29 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	findpos(t_stack *a, int median)
{
	int		*arr;
	int		pos;
	t_node	*node;

	node = a->top;
	pos = 0;
	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		exit(1);
	while (node)
	{
		arr[pos] = node->value;
		node = node->next;
		pos++;
	}
	pos = 0;
	while (arr[pos] != median)
		pos++;
	free(arr);
	return (pos);
}

int	rra(t_stack *a, t_stack *b, int median)
{
	if (a->top->value < median)
	{
		pb(a, b);
		write(1, "pb\n", 3);
		return (1);
	}
	else
	{
		reverotate(a);
		write(1, "rra\n", 4);
		return (0);
	}
}

int	ra(t_stack *a, t_stack *b, int median)
{
	if (a->top->value < median)
	{
		pb(a, b);
		write(1, "pb\n", 3);
		return (1);
	}
	else
	{
		rotate(a);
		write(1, "ra\n", 3);
		return (0);
	}
}

void	push_three_to_b(t_stack *a, t_stack *b, int median)
{
	int	pos;
	int	pushed;

	pos = findpos(a, median);
	pushed = 0;
	while (pushed < 3 && a->size > 0)
	{
		if (pos < a->size / 2)
			pushed += ra(a, b, median);
		else
			pushed += rra(a, b, median);
	}
}

void	mysort(t_stack *a, t_stack *b)
{
	int	median;

	while (a->size > 5)
	{
		median = findmedian(a);
		push_three_to_b(a, b, median);
		if (b->size > 1)
			sort_tiny_inverse(a, b);
	}
	small_sort(a, b);
	while (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
	}
}
