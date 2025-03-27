/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <anoviedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:27:08 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/27 17:48:21 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	**prepend_program_name(char **split_args, int count)
{
	char	**new_argv;
	int		i;

	new_argv = malloc(sizeof(char *) * (count + 2));
	if (!new_argv)
		exit(1);
	new_argv[0] = ft_strdup("push_swap");
	i = 0;
	while (i < count)
	{
		new_argv[i + 1] = split_args[i];
		i++;
	}
	new_argv[i + 1] = NULL;
	return (new_argv);
}

int	transformation(int *argc, char ***argv)
{
	char	**split_args;
	int		count;

	split_args = ft_split((*argv)[1], ' ');
	if (!split_args || !split_args[0])
	{
		write(1, "error\n", 6);
		exit(1);
	}
	count = 0;
	while (split_args[count])
		count++;
	*argv = prepend_program_name(split_args, count);
	free(split_args);
	*argc = count + 1;
	return (1);
}
