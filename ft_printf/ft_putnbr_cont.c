/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:45:19 by anoviedo          #+#    #+#             */
/*   Updated: 2024/10/24 12:31:26 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	minicase(void)
{
	if (ft_putstr_cont("-2147483648") == -1)
		return (-1);
	return (11);
}

int	ft_putnbr_cont(int n)
{
	int	cont;
	int	temp;

	temp = 0;
	cont = 0;
	if (n == -2147483648)
		return (minicase());
	if (n < 0)
	{
		n = -n;
		if (ft_putchar('-') == -1)
			return (-1);
		cont++;
	}
	if (n > 9)
	{
		temp = ft_putnbr_cont(n / 10);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	cont++;
	return (cont);
}
