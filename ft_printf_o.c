/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:17:14 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/09 14:16:46 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_o_print(t_arg *arg, char *str, int len)
{
	if (arg->flag[3] == '#' && str[0] == '0')
	{
		return ;
	}
	else if (str[0] == '0' && arg->precision == 0)
	{
		return ;
	}
	else
	{
		arg->ret += len;
		write(1, str, len);
	}
}


void	ft_printf_o_help_help(t_arg *arg, char *str, int len)
{
	ft_printf_o_print(arg, str, len);
	if (arg->flag[1] == '-')
	{
		if (arg->precision > len)
		{
			if (arg->width > arg->precision)
				ft_printf_putchar(arg->width - arg->precision, " ", arg);
		}
		else if (arg->width > arg->precision)
			if (arg->width > len)
				ft_printf_putchar(arg->width - len, " ", arg);
	}
}

void	ft_printf_o_help(char *str, int len, t_arg *arg)
{
	if (arg->flag[3] == '#')
		arg->width -= 1;
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
	}
	if (arg->precision > len)
		ft_printf_putchar(arg->precision - len, "0", arg);
	else if (arg->flag[3] == '#')
		ft_printf_putchar(1, "0", arg);
	if (arg->precision < 0 && arg->flag[2] == '0' && arg->flag[1] != '-')
		ft_printf_putchar(arg->width - len, "0", arg);
	ft_printf_o_help_help(arg, str, len);
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
