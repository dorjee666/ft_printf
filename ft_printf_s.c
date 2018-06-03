/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:44:48 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 11:23:11 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s_minus(char *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		arg->ret += ft_printf_putstr(arg->precision, str);
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
	}
	else
	{
		arg->ret += ft_printf_putstr(len, str);
		ft_printf_putchar(arg->width - len, " ", arg);
	}
}

void	ft_printf_s_nominus(char *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
		arg->ret += ft_printf_putstr(arg->precision, str);
	}
	else
	{
		ft_printf_putchar(arg->width - len, " ", arg);
		arg->ret += ft_printf_putstr(len, str);
	}
}

void	ft_printf_ws_minus(wchar_t *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		arg->ret += ft_printf_putwstr(arg->precision, str);
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
	}
	else
	{
		arg->ret += ft_printf_putwstr(len, str);
		ft_printf_putchar(arg->width - len, " ", arg);
	}
}

void	ft_printf_ws_nominus(wchar_t *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
		arg->ret += ft_printf_putwstr(arg->precision, str);
	}
	else
	{
		ft_printf_putchar(arg->width - len, " ", arg);
		arg->ret += ft_printf_putwstr(len, str);
	}
}

void	ft_printf_conversion_s(t_arg *arg, char *format)
{
	int		len;
	char	*str;
	wchar_t	*str1;

	if (arg->length[0] == 'l' || *format == 'S')
	{
		str1 = va_arg(arg->ap, wchar_t *);
		len = ft_printf_wstrlen(str1);
		if (arg->flag[1] == '-')
			ft_printf_ws_minus(str1, len, arg);
		else
			ft_printf_ws_nominus(str1, len, arg);
		// free(str1);
		// str1 = NULL;
		return ;
	}
	str = va_arg(arg->ap, char *);
	len = (int)ft_strlen(str);
	if (arg->flag[1] == '-')
		ft_printf_s_minus(str, len, arg);
	else
		ft_printf_s_nominus(str, len, arg);
	// free(str);
	// str = NULL;
}
