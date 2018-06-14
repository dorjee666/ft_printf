/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:35:23 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/14 15:29:23 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

unsigned long long	ft_pow_u(unsigned long long nb, unsigned long long pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow_u(nb, pow - 1));
}

char				*ft_free_zero(char *str, int len)
{
	char	*str1;
	int		start;

	start = (int)ft_strlen(str) - len;
	str1 = malloc(sizeof(char) * start + 1);
	start = 0;
	while (str[len] != '\0')
	{
		str1[start++] = str[len];
		len++;
	}
	str1[start] = '\0';
	ft_strdel(&str);
	return (str1);
}

char				*base_u(unsigned long long value, unsigned long long base)
{
	unsigned long long	i;
	char				*nbr;
	int					len;

	i = 1;
	while (ft_pow_u(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (ft_strlen(nbr) > 1)
	{
		len = 0;
		while (nbr[len] == '0')
			len++;
		nbr = ft_free_zero(nbr, len);
	}
	return (nbr);
}

void				ft_printf_u_help(t_arg *arg, char *str, int len)
{
	if (arg->flag[1] != '-')
	{
		if (arg->width > arg->precision && arg->width > len)
		{
			if (arg->precision >= 0 && arg->precision > len)
				ft_printf_putchar(arg->width - arg->precision, " ", arg);
			else if (arg->precision >= 0 && len > arg->precision)
				ft_printf_putchar(arg->width - len, " ", arg);
		}
		if (arg->precision < 0 && arg->flag[2] != '0')
			ft_printf_putchar(arg->width - len, " ", arg);
		if (arg->precision < 0 && arg->flag[2] == '0')
			ft_printf_putchar(arg->width - len, "0", arg);
		if (arg->precision > len)
			ft_printf_putchar(arg->precision - len, "0", arg);
	}
	write(1, str, ft_strlen(str));
	arg->ret += (int)ft_strlen(str);
	if (arg->flag[1] == '-')
	{
		if (arg->width > len)
			ft_printf_putchar(arg->width - len, " ", arg);
	}
}

void				ft_printf_conversion_u(t_arg *arg, char ch)
{
	unsigned long long	num;
	char				*str;

	num = ft_printf_get_unsigned_long(arg, ch);
	str = base_u(num, 10);
	ft_printf_u_help(arg, str, (int)ft_strlen(str));
	ft_strdel(&str);
	str = NULL;
}
