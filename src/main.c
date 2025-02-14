/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/13 14:15:10 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	int		value;
	int		cont;
	t_stack	stack_a;
	t_stack	stack_b;

	cont = 0;
	if (argc < 2)
		return (0);
	create_stack(&stack_a);
	create_stack(&stack_b);
	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
		{
			write(1, "error\n", 6);
			free_stack(&stack_a);
			free_stack(&stack_b);
			exit(1);
		}
		value = ft_atol(argv[i]);
		push(&stack_a, value);
		i--;
	}
	if (has_duplicate(&stack_a))
	{
		write(1, "error\n", 6);
		free_stack(&stack_a);
		free_stack(&stack_b);
		exit(1);
	}
	// if (argc >= 6)
	/*	printf("el primero es :%d, segundo: %d, y el tercero: %d, cuarto: %d,
			quinto: %d\n", stack_a.top->value, stack_a.top->next->value,
			stack_a.top->next->next->value,
			stack_a.top->next->next->next->value,
			stack_a.top->next->next->next->next->value);*/
	if (stack_a.size == 1)
	{
		printf("\noperations quantity: 0\n");
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	if (stack_a.size <= 3)
	{
		cont = tiny_sort(&stack_a);
		/*	printf("\n luego de tiny_sort: \nel primero es :%d, segundo: %d,
				y el tercero: %d\n", stack_a.top->value,
				stack_a.top->next->value, stack_a.top->next->next->value);*/
		printf("\noperations quantity: %d\n", cont);
		return (cont);
	}
	if (stack_a.size <= 5)
	{
		cont = small_sort(&stack_a, &stack_b);
			printf("\n luego de small_sort: \nel primero es :%d, segundo: %d,\
				y el tercero: %d, el cuarto: %d\n",\
				stack_a.top->value, stack_a.top->next->value,\
				stack_a.top->next->next->value,stack_a.top->next->next->next->value);
				free_stack(&stack_a);
				free_stack(&stack_b);
				printf("\noperations quantity: %d\n", cont);
				return (cont);
	}
	cont = quicksort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	printf("\noperations quantity: %d\n", cont);
	return (0);
}

/*
ANTIGUO MAIN DE PRUEBA
int	main(void)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_node	*current;
	int		value;
	int		error;

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
