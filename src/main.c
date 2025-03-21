/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:27 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/21 15:23:18 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	control_argument(int *argc, char ***argv)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while ((*argv)[1][i])
	{
		if ((*argv)[1][i] == ' ')
		{
			space = 1;
			break ;
		}
		i++;
	}
	if (space)
	{
		transformation(argc, argv);
		return (1);
	}
	return (0);
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
	else if (stack_a->size <= 5)
		small_sort(stack_a, stack_b);
	else if (stack_a->size > 5 && stack_a->size <= 40)
		mysort(stack_a, stack_b);
	else if (stack_a->size > 40)
	{
		sort_radix_index(stack_a);
		sort_radix(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		splited;

	splited = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		splited = control_argument(&argc, &argv);
	create_stack(&stack_a);
	create_stack(&stack_b);
	fill_stack(&stack_a, &stack_b, argc, argv);
	if (stack_a.size == 1 || its_ordered(&stack_a))
	{
		if (splited)
			free_split(argv);
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (splited)
		free_split(argv);
	return (0);
}
