/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:59:43 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/14 20:31:03 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_putstr(int num, char *str)
{
	int		i;
	char	ch;

	i = 0;
	while (str && i < num && str[i] != '\0')
	{
		ch = str[i++];
		write(1, &ch, 1);
	}
	return (i);
}

int		ft_printf_putwstr(int num, wchar_t *str)
{
	int		i;

	i = 0;
	while (i < num)
		write(1, &str[i++], 1);
	return (num);
}

int		ft_printf_wstrlen(wchar_t *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

void	ft_printf_putchar(int num, char *format, t_arg *arg)
{
	if (num > 0)
		arg->ret += num;
	while (num > 0)
	{
		write(1, format, 1);
		num--;
	}
}

int		ft_printf_incomplete(void)
{
	char *str;

	str = "invalid conversion specifier.";
	write(1, str, ft_strlen(str));
	return (1);
}
