/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:42:53 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 21:58:15 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_x_print(char *str, char ch, int len)
{
	int		i;
	int		temp;
	char	tm;

	i = 0;
	if (ch == 'x')
	{
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'F')
			{
				temp = str[i] - 'A';
				tm = 'a' + temp;
				write(1, &tm, 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	else
		write(1, str, len);
}

void	ft_printf_x_help_help(t_arg *arg, char *str, int len, char ch)
{
	arg->ret += len;
	ft_printf_x_print(str, ch, len);
	if (arg->flag[1] == '-')
	{
		if (arg->precision > len)
		{
			if (arg->width > arg->precision)
				ft_printf_putchar(arg->width - arg->precision, " ", arg);
		}
		else if (arg->width > arg->precision)
		{
			if (arg->width > len)
				ft_printf_putchar(arg->width - len, " ", arg);
		}
	}
}

void	ft_printf_x_help(t_arg *arg, char *str, char ch, int len)
{
	if (arg->flag[3] == '#')
		arg->width -= 2;
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
	if (arg->flag[3] == '#' && ft_strlen(str) > 1)
	{
		if (ch == 'x')
			write(1, "0x", 2);
		if (ch == 'X')
			write(1, "0X", 2);
		arg->ret += 2;
	}
	if (arg->precision < 0 && arg->flag[2] == '0' && arg->flag[1] != '-')
		ft_printf_putchar(arg->width - len, "0", arg);
	ft_printf_x_help_help(arg, str, len, ch);
}

void	ft_printf_conversion_x(t_arg *arg, char ch)
{
	int					len;
	char				*str;
	unsigned long long	num;

	num = ft_printf_get_unsigned_long(arg);
	str = ft_itoa_base(num, 16);
	len = ft_strlen(str);
	ft_printf_x_help(arg, str, ch, len);
	free(str);
	str = NULL;
}
