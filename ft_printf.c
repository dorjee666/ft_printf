/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:58:01 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 11:22:05 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_init_arg_flag(t_arg *arg)
{
	int i;

	i = 0;
	while (i < 5)
		arg->flag[i++] = 0;
}

void	ft_printf_init_reset_arg(t_arg *arg)
{
	arg->width = 0;
	arg->precision = (-1);
	arg->str = NULL;
	arg->length[0] = '\0';
	arg->length[1] = '\0';
	arg->length[2] = '\0';
	ft_printf_init_arg_flag(arg);
}

int		ft_print(char *format, t_arg *arg)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
			ft_printf_putchar(1, format++, arg);
		else if (*format == '%')
		{
			format = ft_printf_solve(format, arg);
			if (format == NULL)
				return (-1);
			format--;
			ft_printf_init_reset_arg(arg);
		}
		else
			ft_printf_putchar(1, format, arg);
		format++;
	}
	return (1);
}

/*
**	length = 0 -> no length agument
**	length = 1 -? length argument given
*/

int		ft_printf(const char *format, ...)
{
	va_list	ap2;
	t_arg	*arg;
	int		ret;

	arg = malloc(sizeof(t_arg));
	ft_printf_init_reset_arg(arg);
	arg->ret = 0;
	va_start(arg->ap, format);
	va_copy(ap2, arg->ap);
	if (ft_print((char *)format, arg) == (-1))
	{
		write(1, "it failed miserably\n", 20);
	}
	va_end(ap2);
	ret = arg->ret;
	free(arg);
	arg = NULL;
	return (ret);
}
