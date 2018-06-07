/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:17:14 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/07 15:55:54 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	ft_o_precision(t_arg *arg, char ch, int len)
// {
// 	if (arg->precision > len)
// 	{
// 		if (arg->width > arg->precision)
// 		{
// 			ft_printf_putchar(arg->width - arg->precision, &ch, arg);
// 			ft_printf_putchar(arg->precision - len, "0", arg);
// 		}
// 	}
// }

void	ft_printf_o_help(char *str, int len, t_arg *arg)
{
	if (arg->flag[3] == '#')
		arg->width--;
	if (arg->flag[1] != '-')
	{
		if (arg->width > len)
		{
			if (arg->flag[2] == '0')
				len = len;
				// ft_o_precision(arg, '0', len)
			else
				len = len;
				// ft_o_precision(arg, ' ', len)
		}
	}
	if (arg->flag[3] == '#' && len > 1)
		ft_printf_putchar(1, "0", arg);
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
