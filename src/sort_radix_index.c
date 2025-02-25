/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:18:13 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/21 17:48:56 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*take_array(t_stack *a)
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
	bubble_sort(arr, a->size);
	return (arr);
}

void	sort_radix_index(t_stack *a)
{
	int		i;
	int		*arr;
	t_node	*node;

	arr = take_array(a);
	node = a->top;
	i = 0;
	while (node)
	{
		i = 0;
		while (i < a->size)
		{
			if (node->value == arr[i])
			{
				node->value = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
	free(arr);
}
