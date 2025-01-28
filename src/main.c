/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/28 21:47:31 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/push_swap.h"

int	main(void)
{
	t_stack	stack;
	t_node	*current;
	int		value;

	/*Inicializamos la pila*/

	create_stack(&stack);

	/*Agregamos elementos a la pila*/

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);

	// Mostramos la pila inicial
	current = stack.top;
	printf("Contenido de la pila antes de cualquier operación:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Probamos la operación swap
	swap(&stack);
	current = stack.top;
	printf("\nContenido de la pila después de swap:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Probamos la operación pop
	value = pop(&stack);
	printf("\nEl valor eliminado con pop es: %d\n", value);
	current = stack.top;
	printf("Contenido de la pila después de pop:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Liberamos memoria (puede implementarse más adelante)
	rotate(&stack);
	current = stack.top;
	printf("\nContenido de la pila después de rotate:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	inverotate(&stack);
	current = stack.top;
	printf("\nContenido de la pila después de reverse rotate:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	return (0);
}

/*
gcc -Wall -Wextra -Werror src/main.c
./src/stack_utils.c src/stack_operations.c -o push_swap

*/
