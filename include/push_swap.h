/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:54:39 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/28 15:23:31 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

#endif
