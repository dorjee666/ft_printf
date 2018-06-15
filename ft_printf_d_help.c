/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 01:43:22 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/11 20:42:21 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	intmax_t	ftlen(intmax_t sign)
{
	if (sign == 1)
		return (0);
	return (1);
}

static	char		*numtostr(intmax_t n, int len, intmax_t sign)
{
	char		*str;
	intmax_t	rem;

	if ((str = (char *)malloc(len * sizeof(char) + 1)) == NULL)
		return (NULL);
	if (n > 0)
	{
		str[len--] = '\0';
		while (n > 0)
		{
			rem = n % 10;
			n = n / 10;
			str[len--] = (char)(rem + 48);
		}
		if (sign == (-1))
			str[0] = '-';
	}
	else
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char				*ft_printf_d_itoa(intmax_t n)
{
	char		*str;
	intmax_t	sign;
	intmax_t	ncopy;
	int			len;

	sign = (-1);
	if (n >= 0)
		sign = 1;
	len = ftlen(sign);
	ncopy = n * sign;
	while (ncopy >= 10)
	{
		ncopy = ncopy / 10;
		len++;
	}
	str = numtostr(n * sign, len + 1, sign);
	return (str);
}

intmax_t			ft_printf_get_long(t_arg *arg, char *format)
{
	if (*format == 'D')
		return ((long long)va_arg(arg->ap, long int));
	else if (arg->length[0] == 'l' && arg->length[1] == 'l')
		return (va_arg(arg->ap, intmax_t));
	else if (arg->length[0] == 'l')
		return ((long long)va_arg(arg->ap, long int));
	else if (arg->length[0] == 'h' && arg->length[1] == 'h')
		return ((char)va_arg(arg->ap, int));
	else if (arg->length[0] == 'h')
		return ((short)va_arg(arg->ap, int));
	else if (arg->length[0] == 'j')
		return (va_arg(arg->ap, long long));
	else if (arg->length[0] == 'z')
		return ((long long)va_arg(arg->ap, size_t));
	return ((long long)va_arg(arg->ap, int));
}

int					ft_printf_d_print(t_arg *arg, char *str, int len)
{
	if (str[0] == '0' && arg->precision == 0)
	{
		if (arg->width > 0)
		{
			write(1, " ", 1);
			return (1);
		}
		else
			return (0);
	}
	else
	{
		write(1, str, len);
		return (len);
	}
	return (0);
}
