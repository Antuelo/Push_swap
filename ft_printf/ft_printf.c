/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:21:43 by anoviedo          #+#    #+#             */
/*   Updated: 2024/10/26 14:56:00 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_format(const char *s, size_t *i, va_list args)
{
	int	temp;

	temp = 0;
	(*i)++;
	if (s[*i] == 'c' && s[*i] != '\0')
		temp = ft_putchar(va_arg(args, int));
	else if (s[*i] == 's' && s[*i] != '\0')
		temp = ft_putstr_cont(va_arg(args, const char *));
	else if ((s[*i] == 'i' || s[*i] == 'd') && s[*i] != '\0')
		temp = ft_putnbr_cont(va_arg(args, int));
	else if (s[*i] == 'p' && s[*i] != '\0')
		temp = pmem(va_arg(args, void *));
	else if (s[*i] == 'u' && s[*i] != '\0')
		temp = pnatural(va_arg(args, unsigned int));
	else if (s[*i] == 'x' && s[*i] != '\0')
		temp = phexalow(va_arg(args, unsigned int));
	else if (s[*i] == 'X' && s[*i] != '\0')
		temp = phexaup(va_arg(args, unsigned int));
	else if (s[*i] == '%')
		temp = ft_putchar('%');
	(*i)++;
	return (temp);
}

int	process_string(const char *s, va_list args)
{
	size_t	i;
	int		cont;
	int		temp;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			temp = handle_format(s, &i, args);
			if (temp < 0)
				return (-1);
			cont += temp;
		}
		else
		{
			temp = ft_putchar(s[i]);
			if (temp < 0)
				return (-1);
			cont += temp;
			i++;
		}
	}
	return (cont);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		cont;

	cont = 0;
	va_start(args, s);
	cont = process_string(s, args);
	va_end(args);
	return (cont);
}
 