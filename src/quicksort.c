/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:15 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/18 12:18:46 by anoviedo         ###   ########.fr       */
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
		arr[i++] = node->value;
		node = node->next;
	}
	bubble_sort(arr, a->size);
	median = arr[a->size / 2];
	free(arr);
	return (median);
}

int	push_lower_half_to_b(t_stack *a, t_stack *b, int median)
{
	int	original_size;
	int	count;
	int	i;
	int	pushed;

	original_size = a->size;
	count = 0;
	i = 0;
	pushed = 0;
	while (i < original_size && pushed < original_size / 2)
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
		i++;
	}
	return (count);
}

int	quicksort(t_stack *a, t_stack *b)
{
	int	median;
	int	count;

	count = 0;
	if ((a->size > 1 && a->size <= 5) || (b->size > 1 && b->size <= 3))
	{
		if (a->size > 1 && a->size <= 3)
			count = tiny_sort(a);
		if (b->size > 1 && b->size <= 3)
			count = inverse_tiny_sort(b);
		if (a->size > 3 && a->size <= 5)
			count = small_sort(a, b);
		return (count);
	}
	median = findmedian(a);
	count += push_lower_half_to_b(a, b, median);
	count += quicksort(a, b);
	while (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		count++;
	}
	return (count);
}
