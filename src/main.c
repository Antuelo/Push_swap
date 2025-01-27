/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/27 15:28:34 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(void)
{
	t_stack		stack;
	t_node		*current;

	create_stack(&stack);
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	current = stack.top;
	printf("contenido de la pila:\n");
	while(current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	return (0);
}
