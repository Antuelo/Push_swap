/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:51:06 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/28 21:48:09 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

/*push, pone un numero en lo mas alto de la pila
y desplaza el que estaba antes en segundo lugar*/

void	push(t_stack *stack, int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
	{
		write(1, "malloc fail\n", 12);
		return ;
	}
	newnode->value = value;
	newnode->next = stack->top;
	stack->top = newnode;
	stack->size++;
}

/*pop, Elimina el numero que esta en lo mas alto
devuelve el valor eliminado, y pone en primer lugar
el que anteriormente estaba segundo*/

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->top == NULL)
		return (-1);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

/*cambia la primer posicion por la segunda de un stack*/

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*first;

	if (stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	inverotate(t_stack *stack)
{
	t_node	*last;
	t_node	*penul;

	if (stack->size < 2)
		return ;
	last = stack->top;
	penul = NULL;
	while (last->next)
	{
		penul = last;
		last = last->next;
	}
	penul->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
