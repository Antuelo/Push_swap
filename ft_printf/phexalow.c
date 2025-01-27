/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phexalow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:14:20 by anoviedo          #+#    #+#             */
/*   Updated: 2024/10/24 15:48:46 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	phexalow(unsigned int num)
{
	char	*hexa;
	int		cont;
	int		temp;

	hexa = "0123456789abcdef";
	cont = 0;
	if (num >= 16)
	{
		temp = phexalow(num / 16);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	if (ft_putchar (hexa[num % 16]) == -1)
		return (-1);
	cont++;
	return (cont);
}
