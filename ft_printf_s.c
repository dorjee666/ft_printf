/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:44:48 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 22:03:32 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s_minus(char *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			len = (int)ft_strlen(str);
			arg->ret += ft_printf_putstr(arg->precision, str);
		}
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
	}
	else
	{
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			arg->ret += (int)ft_strlen(str);
			write(1, str, ft_strlen(str));
		}
		ft_printf_putchar(arg->width - (int)ft_strlen(str), " ", arg);
	}
}

void	ft_printf_s_nominus(char *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			len = (int)ft_strlen(str);
			arg->ret += ft_printf_putstr(arg->precision, str);
		}
	}
	else
	{
		ft_printf_putchar(arg->width - (int)ft_strlen(str), " ", arg);
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			arg->ret += (int)ft_strlen(str);
			write(1, str, ft_strlen(str));
		}
	}
}

void	ft_printf_ws_minus(wchar_t *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			len = (int)ft_printf_wstrlen(str);
			arg->ret += ft_printf_putwstr(arg->precision, str);
		}
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
	}
	else
	{
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			len = (int)ft_printf_wstrlen(str);
			arg->ret += ft_printf_putwstr(len, str);
		}
		ft_printf_putchar(arg->width - len, " ", arg);
	}
}

void	ft_printf_ws_nominus(wchar_t *str, int len, t_arg *arg)
{
	if (arg->precision <= len && arg->precision >= 0)
	{
		ft_printf_putchar(arg->width - arg->precision, " ", arg);
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			len = (int)ft_printf_wstrlen(str);
			arg->ret += ft_printf_putwstr(arg->precision, str);
		}
	}
	else
	{
		ft_printf_putchar(arg->width - len, " ", arg);
		if (!str)
			arg->ret += ft_printf_putstr(6, "(null)");
		else
		{
			len = (int)ft_printf_wstrlen(str);
			arg->ret += ft_printf_putwstr(len, str);
		}
	}
}

void	ft_printf_conversion_s(t_arg *arg, char *format)
{
	char	*str;
	wchar_t	*str1;

	if (arg->length[0] == 'l' || *format == 'S')
	{
		str1 = va_arg(arg->ap, wchar_t *);
		if (arg->flag[1] == '-')
			ft_printf_ws_minus(str1, 6, arg);
		else
			ft_printf_ws_nominus(str1, 6, arg);
		return ;
	}
	str = va_arg(arg->ap, char *);
	if (arg->flag[1] == '-')
		ft_printf_s_minus(str, 6, arg);
	else
		ft_printf_s_nominus(str, 6, arg);
}
