/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:15 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 18:38:32 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	findpos(t_stack *a, int median)
{
	int		*arr;
	int		i;
	t_node	*node;

	node = a->top;
	i = 0;
	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		exit(1);
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	i = 0;
	while (arr[i] != median)
		i++;
	free(arr);
	return (i);
}

int	rra(t_stack *a, t_stack *b, int median)
{
	if (a->top->value < median)
	{
		pb(a, b);
		printf("LA MEDIAN EN rra ES : %d\n", median);
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
		printf("la media en RA es : %d\n", median);
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

int	quicksort(t_stack *a, t_stack *b)
{
	int	median;
	int	count;
	int	pos;
	int	pushed;

	count = 0;
	while (a->size > 5)
	{
		median = findmedian(a);
		pos = findpos(a, median);
		printf("Nueva median: %d\n la posicion es : %d\n", median, pos);
		pushed = 0;
		while (pushed < 3 && a->size > 0)
		{
			if (pos < a->size / 2)
				pushed += ra(a, b, median);
			else
				pushed += rra(a, b, median);
		}
		print_stacks(a, b);
		if (b->size > 1)
		{
			count += sort_tiny_inverse(a, b);
			printf("aqui aplicamos inverse tiny sort");
			print_stacks(a, b);
		}
	}
	small_sort(a, b);
	while (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		count++;
	}
	return (count);
}

/*int	push_lower_half_to_b(t_stack *a, t_stack *b, int median, int pos)
{
	int	count;
	int	pushed;

	count = 0;
	pushed = 0;
	while (pushed != 1)
	{
		if (pos < a->size / 2)
			pushed = ra(a, b, median);
		else
			pushed = rra(a, b, median);
		count++;
	}
	return (count);
}*/
