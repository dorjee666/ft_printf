/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_percent.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:55:33 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/14 20:41:21 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversion_percent(t_arg *arg)
{
	if (arg->flag[1] != '-')
	{
		if (arg->flag[2] == '0')
			ft_printf_putchar(arg->width - 1, "0", arg);
		else
			ft_printf_putchar(arg->width - 1, " ", arg);
	}
	arg->ret += 1;
	write(1, "%", 1);
	if (arg->flag[1] == '-')
		ft_printf_putchar(arg->width - 1, " ", arg);
}
