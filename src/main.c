/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/05 17:00:25 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int			i;
	int			value;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc < 2)
		return (0);
	create_stack(&stack_a);
	create_stack(&stack_b);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			write(1, "error\n", 6);
			exit(1);
		}
		value = ft_atol(argv[i]);
		push(&stack_a, value);
		i++;
	}
	if (has_duplicate(&stack_a))
	{
		write(1, "error\n", 6);
		exit(1);
	}
	return (0);
}

/*
ANTIGUO MAIN DE PRUEBA
int	main()
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_node		*current;
	int			value;
	int			error;

	if (!is_valid_number(v[i]))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (has_duplicate(&stack_a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}

	create_stack(&stack_a);
	create_stack(&stack_b);


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
	error = 0;
	value = pop(&stack_a, &error);
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
	reverotate(&stack_a);
	current = stack_a.top;
	printf("\nContenido de la pila después de reverse rotate:\n");
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Aplicamos pb (movemos de A a B)

	pb(&stack_a, &stack_b);
	printf("\nContenido de la pila A después de pb:\n");
	current = stack_a.top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("\nContenido de la pila B después de pb:\n");
	current = stack_b.top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}

	// Aplicamos pa (movemos de B a A)
	pa(&stack_a, &stack_b);
	printf("\nContenido de la pila A después de pa:\n");
	current = stack_a.top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("\nContenido de la pila B después de pa:\n");
	current = stack_b.top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	return (0);
}
*/
