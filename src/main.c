/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/28 00:55:46 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/push_swap.h"
#include "../ft_printf/libftprintf.h"

int	main(void)
{
	t_stack		stack;
	t_node		*current;
	int			value;

	create_stack(&stack);
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	current = stack.top;
	ft_printf("contenido de la pila antes de pop:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	value = pop(&stack);
	current = stack.top;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
	ft_printf("el valor eliminado es: %d\n", value);
	return (0);
}

/*
gcc -Wall -Wextra -Werror src/main.c src/stack_utils.c
 src/stack_operations.c -o push_swap
*/
