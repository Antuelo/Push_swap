/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoviedo <antuel@outlook.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:45:30 by anoviedo          #+#    #+#             */
/*   Updated: 2024/10/24 15:43:38 by anoviedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putstr_cont(const char *s);
int	ft_putchar(char c);
int	ft_putnbr_cont(int n);
int	ft_printf(const char *s, ...);
int	phexalow(unsigned int num);
int	phexaup(unsigned int num);
int	pmem(void *h);
int	pnatural(unsigned int n);

#endif
