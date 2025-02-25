/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny_inverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:32:31 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/25 18:30:03 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

typedef struct s_values
{
	int	f;
	int	s;
	int	t;
}		t_values;

int	first_inverse_case(t_stack *a, t_stack *b, t_values vals)
{
	if (vals.f < vals.s && vals.f > vals.t && vals.s > vals.t)
	{
		swap(b);
		write(1, "sb\n", 3);
		return (1);
	}
	if (vals.f < vals.s && vals.s < vals.t && vals.f < vals.t)
	{
		swap(b);
		write(1, "sb\npa\nsb\npb\nsb\n", 15);
		pa(a, b);
		swap(b);
		pb(a, b);
		swap(b);
		return (5);
	}
	if (vals.f > vals.s && vals.s < vals.t && vals.f < vals.t)
	{
		pa(a, b);
		write(1, "pa\nsb\npb\nsb\n", 12);
		swap(b);
		pb(a, b);
		swap(b);
		return (4);
	}
	return (0);
}

int	second_inverse_case(t_stack *a, t_stack *b, t_values vals)
{
	if (vals.f > vals.s && vals.s < vals.t && vals.f > vals.t)
	{
		write(1, "pa\nsb\npb\n", 9);
		pa(a, b);
		swap(b);
		pb(a, b);
		return (3);
	}
	if (vals.f < vals.s && vals.s > vals.t)
	{
		swap(b);
		write(1, "sb\n", 3);
		pa(a, b);
		write(1, "pa\n", 3);
		swap(b);
		write(1, "sb\n", 3);
		pb(a, b);
		write(1, "pb\n", 3);
		return (4);
	}
	return (0);
}

int	sort_tiny_inverse(t_stack *a, t_stack *b)
{
	t_values	vals;
	int			cont;

	cont = 0;
	if (b->size == 2)
	{
		if (b->top->value < b->top->next->value)
		{
			swap(a);
			write(1, "sb\n", 3);
			return (1);
		}
		return (0);
	}
	vals.f = b->top->value;
	vals.s = b->top->next->value;
	vals.t = b->top->next->next->value;
	if (vals.f > vals.s && vals.s > vals.t)
		return (0);
	cont = first_inverse_case(a, b, vals);
	if (cont == 0)
		cont = second_inverse_case(a, b, vals);
	return (cont);
}

/*#include "../include/push_swap.h"

int	first_inverse_case(t_stack *a, t_stack *b, int f, int s, int t)
{
	if (f < s && f > t && s > t)
	{
		swap(b);
		write(1, "sb\n", 3);
		return (1);
	}
	if (f < s && s < t && f < t)
	{
		swap(b);
		write(1, "sb\npa\nsb\npb\nsb\n", 15);
		pa(a, b);
		swap(b);
		pb(a, b);
		swap(b);
		return (5);
	}
	if (f > s && s < t && f < t)
	{
		pa(a, b);
		write(1, "pa\nsb\npb\nsb\n", 12);
		swap(b);
		pb(a, b);
		swap(b);
		return (4);
	}
	return (0);
}

int	second_inverse_case(t_stack *a, t_stack *b, int f, int s, int t)
{
	if (f > s && s < t && f > t)
	{
		write(1, "pa\nsb\npb\n", 9);
		pa(a, b);
		swap(b);
		pb(a, b);
		return (3);
	}
	if (f < s && s > t)
	{
		swap(b);
		write(1, "sb\n", 3);
		pa(a, b);
		write(1, "pa\n", 3);
		swap(b);
		write(1, "sb\n", 3);
		pb(a, b);
		write(1, "pb\n", 3);
		return (4);
	}
	return (0);
}

int	sort_tiny_inverse(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;
	int	cont;

	cont = 0;
	if (a->size == 2)
	{
		if (!its_ordered(a))
		{
			swap(a);
			write(1, "sa\n", 3);
			return (1);
		}
		return (0);
	}
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second > third)
		return (0);
	cont = first_inverse_case(a, b, first, second, third);
	if (cont == 0)
		cont = second_inverse_case(a, b, first, second, third);
	return (cont);
}
*/
