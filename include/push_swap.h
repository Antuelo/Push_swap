/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <anoviedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:54:39 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/27 17:44:00 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_values
{
	int				f;
	int				s;
	int				t;
}					t_values;

void				create_stack(t_stack *stack);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				reverotate(t_stack *stack);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
int					is_valid_number(char *str);
long				ft_atol(const char *str);
char				**ft_split(char const *s, char c);
int					has_duplicate(t_stack *stack);
void				tiny_sort(t_stack *stack);
void				small_sort(t_stack *a, t_stack *b);
void				free_stack(t_stack *stack);
int					its_ordered(t_stack *a);
void				mysort(t_stack *a, t_stack *b);
int					findmedian(t_stack *a);
void				sort_radix(t_stack *a, t_stack *b);
void				sort_radix_index(t_stack *a);
void				bubble_sort(int *arr, int size);
int					*take_array(t_stack *a);
void				sort_tiny_inverse(t_stack *a, t_stack *b);
int					*be_array(t_stack *a);
int					transformation(int *argc, char ***argv);
void				free_split(char **arr);
char				*ft_strdup(const char *s);

#endif
