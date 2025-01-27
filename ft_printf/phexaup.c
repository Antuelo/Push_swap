/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phexaup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:25:40 by anoviedo          #+#    #+#             */
/*   Updated: 2024/10/24 15:49:10 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	phexaup(unsigned int num)
{
	char	*hexa;
	int		cont;
	int		temp;

	hexa = "0123456789ABCDEF";
	cont = 0;
	if (num >= 16)
	{
		temp = phexaup(num / 16);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	if (ft_putchar (hexa[num % 16]) == -1)
		return (-1);
	cont++;
	return (cont);
}
