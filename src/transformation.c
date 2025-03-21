/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 09:27:08 by anoviedo          #+#    #+#             */
/*   Updated: 2025/03/21 10:32:05 by anoviedo         ###   ########.fr       */
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

void	transformation(int *argc, char ***argv)
{
	char	**args;

	args = ft_split((*argv)[1], ' ');
	if (!args || !args[0])
	{
		free_split(args);
		write(1, "error\n", 6);
		exit(1);
	}
	*argv = args;
	*argc = 0;
	while (args[*argc])
		(*argc)++;
}
