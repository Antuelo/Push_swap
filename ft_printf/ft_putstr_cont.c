/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:44:42 by anoviedo          #+#    #+#             */
/*   Updated: 2024/10/26 15:34:56 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_cont(const char *s)
{
	size_t	i;

	if (s == NULL)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		else
			return (6);
	}
	i = 0;
	while (s[i] != '\0')
		i++;
	if (write (1, s, i) == -1)
		return (-1);
	return (i);
}
