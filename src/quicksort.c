/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:15 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/19 00:57:05 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	findmedian(t_stack *a)
{
	int		*arr;
	int		i;
	int		median;
	t_node	*node;

	i = 0;
	node = a->top;
	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		exit(1);
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	bubble_sort(arr, a->size);
	median = arr[2];
	free(arr);
	return (median);
}

int	push_lower_half_to_b(t_stack *a, t_stack *b, int median)
{
	int	count;
	int	pushed;

	count = 0;
	pushed = 0;
	while (pushed < 2 || count < a->size)
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
			count += inverse_tiny_sort(b);
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
