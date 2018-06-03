/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:42:30 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 11:22:41 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p_help(t_arg *arg, char *str)
{
	int len;

	len = ft_strlen(str);
	if (arg->flag[1] != '-')
		ft_printf_putchar(arg->width - len - 2, " ", arg);
	write(1, "0x", 2);
	arg->ret += len;
	arg->ret += 2;
	write(1, str, len);
	if (arg->flag[1] == '-')
		ft_printf_putchar(arg->width - len - 2, " ", arg);
}

void	ft_printf_conversion_p(t_arg *arg)
{
	char		*str;
	intmax_t	num;

	num = (intmax_t)va_arg(arg->ap, int);
	str = ft_itoa_base(num, 16);
	ft_printf_p_help(arg, str);
	// free(str);
	// str = NULL;
}
