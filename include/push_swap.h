/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:54:39 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/29 20:05:26 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/libftprintf.h"

typedef struct s_node
{
	int					value;
	struct s_node		*next;
}						t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}				t_stack;

void	create_stack(t_stack *stack);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	inverotate(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
int		is_valid_number(char *str);
#endif
