/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:30:36 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/26 00:38:01 by anoviedo         ###   ########.fr       */
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
	bubble_sort(arr, a->size);
	median = arr[3];
	free(arr);
	return (median);
}

int	*be_array(t_stack *a)
{
	int		*arr;
	int		i;
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
	return (arr);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;

	current_a = a->top;
	current_b = b->top;
	printf("\nStack A: ");
	while (current_a)
	{
		printf("%d ", current_a->value);
		current_a = current_a->next;
	}
	printf("\nStack B: ");
	while (current_b)
	{
		printf("%d ", current_b->value);
		current_b = current_b->next;
	}
	printf("\n-----------------------------------\n");
}
