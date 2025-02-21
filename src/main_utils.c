/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:19:39 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/20 08:19:51 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	t_node	*node;

	printf("stack_a: ");
	node = a->top;
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n");
	printf("stack_b: ");
	node = b->top;
	while (node)
	{
		printf("%d ", node->value);
		node = node->next;
	}
	printf("\n\n");
}
