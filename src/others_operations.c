/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:27:21 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/29 17:36:15 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void pa(t_stack *a, t_stack *b)
{
	int		value;

	if (b->top == NULL)
		return ;
	value = pop(a);
	push(db, value);
}

void pb(t_stack *a, t_stack *b)
{
	int		value;

	if (a->top == NULL)
		return ;
	value = pop(b);
	push(a, value);
}
