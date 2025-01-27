/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:38:40 by anoviedo          #+#    #+#             */
/*   Updated: 2024/10/24 15:49:29 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_hexa(unsigned long address)
{
	char	*hexa;
	int		cont;
	int		temp;

	hexa = "0123456789abcdef";
	cont = 0;
	if (address >= 16)
	{
		temp = print_hexa(address / 16);
		if (temp == -1)
			return (-1);
		cont += temp;
	}
	if (ft_putchar (hexa[address % 16]) == -1)
		return (-1);
	cont++;
	return (cont);
}

int	pmem(void *h)
{
	unsigned long	address;
	int				cont;
	int				temp;

	if (h == NULL)
		return (ft_putstr_cont ("(nil)"));
	address = (unsigned long)h;
	cont = ft_putstr_cont("0x");
	if (cont == -1)
		return (-1);
	temp = print_hexa(address);
	if (temp == -1)
		return (-1);
	cont += temp;
	return (cont);
}
