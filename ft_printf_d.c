/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:26:22 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 23:41:57 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_d_plus_help(char *str, int len, t_arg *arg)
{
	if (arg->flag[1] != '-')
	{
		if (arg->flag[0] == ' ' || arg->flag[0] == '+')
			arg->width--;
		if (arg->width > arg->precision && arg->width > len)
		{
			if (arg->precision >= 0 && arg->precision >= len)
				ft_printf_putchar(arg->width - arg->precision, " ", arg);
			else if (arg->precision >= 0 && len > arg->precision)
				ft_printf_putchar(arg->width - len, " ", arg);
		}
		if (arg->precision < 0 && arg->flag[2] != '0')
			ft_printf_putchar(arg->width - len, " ", arg);
		if (arg->flag[0] == ' ')
			ft_printf_putchar(1, " ", arg);
		else if (arg->flag[0] == '+')
			ft_printf_putchar(1, "+", arg);
		if (arg->precision < 0 && arg->flag[2] == '0')
			ft_printf_putchar(arg->width - len, "0", arg);
		if (arg->precision > len)
			ft_printf_putchar(arg->precision - len, "0", arg);
		arg->ret += ft_printf_putstr(len, str);
	}
}

void	ft_printf_d_plus(int len, char *str, t_arg *arg)
{
	if (arg->flag[1] == '-')
	{
		if (arg->flag[0] == ' ' || arg->flag[0] == '+')
		{
			if (arg->flag[0] == ' ')
				ft_printf_putchar(1, " ", arg);
			else if (arg->flag[0] == '+')
				ft_printf_putchar(1, "+", arg);
			if (arg->width > arg->precision && arg->width > len)
				arg->width--;
		}
		if (arg->precision > len)
			ft_printf_putchar(arg->precision - len, "0", arg);
		arg->ret += ft_printf_putstr(len, str);
		if (arg->width > arg->precision && arg->width > len)
		{
			if (arg->precision > len)
				ft_printf_putchar(arg->width - arg->precision, " ", arg);
			else
				ft_printf_putchar(arg->width - len, " ", arg);
		}
	}
	ft_printf_d_plus_help(str, len, arg);
}

void	ft_printf_d_minus_help(char *str, int len, t_arg *arg)
{
	if (arg->flag[1] != '-')
	{
		arg->width--;
		if (arg->width > arg->precision && arg->width > len)
		{
			if (arg->precision >= 0 && arg->precision >= len)
				ft_printf_putchar(arg->width - arg->precision, " ", arg);
			else if (arg->precision >= 0 && len > arg->precision)
				ft_printf_putchar(arg->width - len, " ", arg);
		}
		if (arg->precision < 0 && arg->flag[2] != '0')
			ft_printf_putchar(arg->width - len, " ", arg);
		ft_printf_putchar(1, "-", arg);
		if (arg->precision < 0 && arg->flag[2] == '0')
			ft_printf_putchar(arg->width - len, "0", arg);
		if (arg->precision > len)
			ft_printf_putchar(arg->precision - len, "0", arg);
		arg->ret += ft_printf_putstr(len, str);
	}
}

void	ft_printf_d_minus(int len, char *str, t_arg *arg)
{
	if (arg->flag[1] == '-')
	{
		ft_printf_putchar(1, "-", arg);
		if (arg->width > arg->precision && arg->width > len)
			arg->width--;
		if (arg->precision > len)
			ft_printf_putchar(arg->precision - len, "0", arg);
		write(1, str, ft_strlen(str));
		arg->ret += ft_strlen(str);
		if (arg->width > arg->precision && arg->width > len)
		{
			if (arg->precision > len)
				ft_printf_putchar(arg->width - arg->precision, " ", arg);
			else
				ft_printf_putchar(arg->width - len, " ", arg);
		}
	}
	ft_printf_d_minus_help(str, len, arg);
}

void	ft_printf_conversion_d(t_arg *arg, char *format)
{
	long long	num;
	char		*str;
	int			len;

	num = ft_printf_get_long(arg, format);
	str = ft_printf_d_itoa(num);
	len = (int)ft_strlen(str);
	if (num < 0)
	{
		len--;
		str++;
		ft_printf_d_minus(len, str, arg);
	}
	else
		ft_printf_d_plus(len, str, arg);
	// if (!str)
	// 	free(str);
	// str = NULL;
}
