/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_percent.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 22:55:33 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 23:20:14 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversion_percent(t_arg *arg)
{
	if (arg->flag[1] != '-')
		ft_printf_putchar(arg->width, " ", arg);
	arg->ret += 1;
	write(1, "%", 1);
	if (arg->flag[1] == '-')
		ft_printf_putchar(arg->width, " ", arg);
}
