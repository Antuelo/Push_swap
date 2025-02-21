/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_inverse_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:33:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/20 08:11:48 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_inverse_b(t_stack *stack_b)
{
	if (stack_b->top->value < stack_b->top->next->value)
	{
		swap(stack_b);
		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}
