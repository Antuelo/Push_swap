/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/29 17:35:20 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/push_swap.h"

int	main(void)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_node		*current;
	int			value;

	/*Inicializamos la pila*/

	create_stack(&stack_a);
	create_stack(&stack_b);

	/*Agregamos elementos a la pila*/

	push(&stack_a, 10);
	push(&stack_a, 20);
	push(&stack_a, 30);

	// Mostramos la pila inicial
	current = stack_a.top;
	printf("Contenido de la pila antes de cualquier operación:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Probamos la operación swap
	swap(&stack_a);
	current = stack_a.top;
	printf("\nContenido de la pila después de swap:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Probamos la operación pop
	value = pop(&stack_a);
	printf("\nEl valor eliminado con pop es: %d\n", value);
	current = stack_a.top;
	printf("Contenido de la pila después de pop:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Liberamos memoria (puede implementarse más adelante)
	rotate(&stack_a);
	current = stack_a.top;
	printf("\nContenido de la pila después de rotate:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	inverotate(&stack_a);
	current = stack_a.top;
	printf("\nContenido de la pila después de reverse rotate:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	//aplicamos pb

	current = stack_a.top;
	pb(&stack_a, &stack_b);
	printf("\nContenido de la pila después de pb:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	//aplicamos pa

	current = stack_a.top;
	pa(&stack_a, &stack_b);
	printf("\nContenido de la pila después de pb:\n");
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
