/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/21 18:02:10 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	int		value;
	int		cont;
	int		*number;
	t_node	*node;
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
	if (stack_a.size == 1 || !its_ordered(&stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	/*sort_radix_index(&stack_a);
	cont += sort_radix(&stack_a, &stack_b);*/
	if (stack_a.size <= 3)
		cont += tiny_sort(&stack_a);
	if (stack_a.size > 3 && stack_a.size <= 5)
		cont += small_sort(&stack_a, &stack_b);
	if (stack_a.size > 5)
		cont += quicksort(&stack_a, &stack_b);
	i = 0;
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	number = malloc(sizeof(int) * stack_a.size);
	if (!number)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	node = stack_a.top;
	while (node)
	{
		number[i] = node->value;
		node = node->next;
		i++;
	}
	i = 0;
	while (i < stack_a.size)
	{
		printf("%d ", number[i]);
		i++;
	}
	printf("\nla cantidad de movimientos fueron: %d\n", cont);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
