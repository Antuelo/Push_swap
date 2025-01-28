/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnatural.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:00:14 by anoviedo          #+#    #+#             */
/*   Updated: 2025/01/28 15:23:26 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pnatural(unsigned int n)
{
	int	cont;
	int	temp;

	temp = 0;
	cont = 0;
	if (n > 9)
	{
		temp = pnatural(n / 10);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	cont++;
	return (cont);
}
