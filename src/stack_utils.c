/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:26:54 by anoviedo          #+#    #+#             */
/*   Updated: 2025/02/20 08:12:09 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* generer un stack vide ... pour le debut du programme
crea un stack vacio (para el comienzo del programa) */

void	create_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

/*	verifier si c'est une chiffre	(RETURN 1)
	dans le cas contraire 			(RETURN 0)
Verifica si es un número */

int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

/* fonction necessaire pour savoir si c'est une
chiffre plus petit ou plus grande que un INT ...
funcion necesaria para saber si es un número: transformar un digito "long" */

long	ft_atol(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	stack->top = NULL;
	stack->size = 0;
}

int	its_ordered(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}
