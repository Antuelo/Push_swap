/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/16 13:02:08 by anoviedo         ###   ########.fr       */
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
	if (stack_a.size == 1)
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	if (stack_a.size <= 3)
	{
		cont = tiny_sort(&stack_a);
		return (cont);
	}
	if (stack_a.size <= 5)
	{
		cont = small_sort(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (cont);
	}
	cont = quicksort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
