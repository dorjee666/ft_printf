/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:43:15 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 10:29:15 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_check_flag(char *format, t_arg *arg)
{
	while (*format && ft_printf_check_flags(*format))
	{
		if (*format == ' ' && arg->flag[0] == 0)
			arg->flag[0] = *format;
		else if (*format == '+')
			arg->flag[0] = *format;
		else if (*format == '-')
			arg->flag[1] = *format;
		else if (*format == '0')
			arg->flag[2] = '0';
		else if (*format == '#')
			arg->flag[3] = '#';
		format++;
	}
	return (format);
}

static char	*ft_check_width(char *format, t_arg *arg)
{
	int n;

	n = 0;
	while (ft_isdigit(*format))
	{
		n = n * 10 + (*format - '0');
		format++;
	}
	arg->width = n;
	return (format);
}

static char	*ft_check_precision(char *format, t_arg *arg)
{
	int n;

	n = 0;
	if (*format == '.')
	{
		format++;
		while (ft_isdigit(*format))
		{
			n = n * 10 + (*format - '0');
			format++;
		}
		arg->precision = n;
	}
	// if (ft_printf_is_modifier(*format) != 1)
	// 	if (ft_printf_is_conversions(format) != 1)
	// 		write(1, "error 008, conversion missing\n", 30);
	return (format);
}

static char	*ft_printf_modifier(char *format, t_arg *arg)
{
	int	i;

	i = 0;
	while (ft_printf_is_modifier(*format) == 1)
	{
		if (i == 2)
			return (NULL);
		arg->length[i++] = *format;
		format++;
	}
	if (arg->length[1] != '\0' && arg->length[0] != arg->length[1])
		return (NULL);
	if (arg->length[1] == 'z' || arg->length[1] == 'j')
		return (NULL);
	return (format);
}

char		*ft_printf_solve(char *format, t_arg *arg)
{
	format++;
	if ((format = ft_check_flag(format, arg)) == NULL)
		write(1, "check_flag, error message\n", 11 + 15);
	if ((format = ft_check_width(format, arg)) == NULL)
		write(1, "check_width, error message\n", 12 + 15);
	if ((format = ft_check_precision(format, arg)) == NULL)
		write(1, "check precision, error message\n", 15 + 15);
	if ((format = ft_printf_modifier(format, arg)) == NULL)
		write(1, "check length, error message\n", 13 + 15);
	format = ft_printf_conversion(format, arg);
	return (format);
}
