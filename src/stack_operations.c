/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:51:06 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/27 15:13:10 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_node *newnode;
	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return;
	newnode->value = value;
	newnode->next = stack->top;
	stack->top = newnode;
	stack->size++;
}
