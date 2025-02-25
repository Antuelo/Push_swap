/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 22:05:13 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	create_stack(stack_a);
	create_stack(stack_b);
}

void	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "error\n", 6);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void	fill_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	int	i;
	int	value;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
			handle_error(stack_a, stack_b);
		value = ft_atol(argv[i]);
		push(stack_a, value);
		i--;
	}
	if (has_duplicate(stack_a))
		handle_error(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		tiny_sort(stack_a);
	else if (stack_a->size > 3 && stack_a->size <= 5)
		small_sort(stack_a, stack_b);
	else if (stack_a->size > 5 && stack_a->size <= 50)
		mysort(stack_a, stack_b);
	else if (stack_a->size > 5)
	{
		sort_radix_index(stack_a);
		sort_radix(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	init_stacks(&stack_a, &stack_b);
	fill_stack(&stack_a, &stack_b, argc, argv);
	if (stack_a.size == 1 || !its_ordered(&stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
