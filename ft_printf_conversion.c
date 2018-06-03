/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:50:10 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/01 23:28:31 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversion_c(t_arg *arg)
{
	char	c;
	wchar_t	c1;

	if (arg->length[0] == 'l')
	{
		c1 = va_arg(arg->ap, wchar_t);
		if (arg->flag[1] != '-')
			ft_printf_putchar(arg->width - 1, " ", arg);
		ft_putwchar(c1);
		arg->ret++;
		if (arg->flag[1] == '-')
			ft_printf_putchar(arg->width - 1, " ", arg);
		return ;
	}
	c = va_arg(arg->ap, int);
	if (arg->flag[1] != '-')
		ft_printf_putchar(arg->width - 1, " ", arg);
	ft_printf_putchar(1, &c, arg);
	if (arg->flag[1] == '-')
		ft_printf_putchar(arg->width - 1, " ", arg);
}

/*
**	if conversion is missing return NULL
*/

char	*ft_printf_conversion(char *format, t_arg *arg)
{
	if (ft_printf_is_conversions(format) == (-1))
		return (NULL);
	if (*format == 'd' || *format == 'i' || *format == 'D')
		ft_printf_conversion_d(arg);
	else if (*format == 'c' || *format == 'C')
		ft_printf_conversion_c(arg);
	else if (*format == 's' || *format == 'S')
		ft_printf_conversion_s(arg, format);
	else if (*format == 'p')
		ft_printf_conversion_p(arg);
	else if (*format == 'o' || *format == 'O')
		ft_printf_conversion_o(arg);
	else if (*format == 'x' || *format == 'X')
		ft_printf_conversion_x(arg, *format);
	else if (*format == 'u' || *format == 'U')
		ft_printf_conversion_u(arg);
	format++;
	return (format);
}
