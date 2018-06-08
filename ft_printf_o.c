/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:17:14 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/07 18:24:00 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_o_help_help(t_arg *arg, int len)
{
	if (arg->precision > 0 && arg->precision > len)
	{
		if (arg->width > arg->precision)
			ft_printf_putchar(arg->width - arg->precision, " ", arg);
	}
	else if (arg->precision >= 0)
		ft_printf_putchar(arg->width - len, " ", arg);
	else if (arg->precision < 0)
	{
		if (arg->flag[2] == '0')
			ft_printf_putchar(arg->width - len, "0", arg);
		else
			ft_printf_putchar(arg->width - len, " ", arg);
	}
}

void	ft_o_start(t_arg *arg)
{
	if (arg->precision == 0)
	{
		ft_printf_putchar(arg->width - 1, " ", arg);
		if (arg->flag[3] == '#')
			ft_printf_putchar(1, "0", arg);
		else
			ft_printf_putchar(1, " ", arg);
	}
	else if (arg->precision > 0)
	{
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
		ft_printf_putchar(arg->precision, "0", arg);
	}
	else
	{
		if (arg->flag[2] == '0')
			ft_printf_putchar(arg->width , "0", arg);
		else
		{
			if (arg->flag[3] == '#')
				ft_printf_putchar(1, "0", arg);
			else
				ft_printf_putchar(1, " ", arg);
		}
	}
}

void	ft_printf_o_help(char *str, int len, t_arg *arg)
{
	if (str[0] == '0')
	{
		ft_o_start(arg);
		return ;
	}
	if (arg->flag[3] == '#')
		if (arg->precision <= 0)
			arg->precision = 1;
	if (arg->flag[1] != '-')
		ft_printf_o_help_help(arg, len);
	if (arg->precision > 0)
		ft_printf_putchar(arg->precision - len, "0", arg);
	arg->ret += len;
	write(1, str, len);
	if (arg->flag[1] == '-')
		ft_printf_putchar(arg->width - len, " ", arg);
}

void	ft_printf_conversion_o(t_arg *arg)
{
	char				*str;
	unsigned long long	num;

	num = ft_printf_get_unsigned_long(arg);
	str = ft_itoa_base(num, 8);
	ft_printf_o_help(str, ft_strlen(str), arg);
	// if (!str)
	// 	free(str);
	str = NULL;
}
