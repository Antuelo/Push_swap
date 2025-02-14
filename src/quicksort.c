/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:03:15 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/13 14:06:07 by anoviedo         ###   ########.fr       */
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
	{
		write(2, "Error: malloc failed in findmedian\n", 35);
		exit(1);
	}
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
	int	count;
	int	original_size;

	original_size = a->size;
	count = 0;
	while (a->size > original_size / 2)
	{
		if (a->top->value < median)
		{
			pb(a, b);
			count++;
		}
		else
		{
			rotate(a);
			count++;
		}
	}
	return (count);
}

int	quicksort(t_stack *a, t_stack *b)
{
	int	median;
	int	count;

	if (its_ordered(a) || a->size <= 1)
		return (0);
	count = 0;
	if (a->size <= 3)
		return (count = tiny_sort(a));
	if (a->size <= 5)
		return (count = small_sort(a, b));
	median = findmedian(a);
	count += push_lower_half_to_b(a, b, median);
	count += quicksort(a, b);
	if (b->size > 0)
		count += quicksort(b, a);
	while (b->size > 0)
	{
		pa(a, b);
		write(1, "pa\n", 3);
		count++;
	}
	return (count);
}
