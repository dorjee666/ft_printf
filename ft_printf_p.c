/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:42:30 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 15:15:56 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_blah(char *str, int len)
{
	char temp;

	while (len-- > 0)
	{
		if (*str >= 'A' && *str <= 'F')
		{
			temp = 'a' + (*str - 'A');
			write(1, &temp, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}

void	ft_printf_p_help(t_arg *arg, char *str)
{
	int len;

	len = ft_strlen(str);
	if (arg->flag[1] != '-')
		ft_printf_putchar(arg->width - len - 2, " ", arg);
	write(1, "0x", 2);
	arg->ret += len;
	arg->ret += 2;
	// write(1, str, len);
	ft_printf_blah(str, len);
	if (arg->flag[1] == '-')
		ft_printf_putchar(arg->width - len - 2, " ", arg);
}

void	ft_printf_conversion_p(t_arg *arg)
{
	char				*str;
	unsigned long long	num;

	num = (unsigned long long)va_arg(arg->ap, unsigned long long int);
	str = ft_itoa_base(num, 16);
	ft_printf_p_help(arg, str);
	free(str);
	str = NULL;
}
