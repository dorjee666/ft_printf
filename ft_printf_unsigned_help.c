/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_help.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 02:01:38 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 10:10:27 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		*numtostr(unsigned long long n, int len)
{
	char		*str;
	long long	rem;

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
	}
	else
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

char				*ft_printf_itoa(unsigned long long n)
{
	char				*str;
	unsigned long long	ncopy;
	int					len;

	len = 0;
	ncopy = n;
	while (ncopy >= 10)
	{
		ncopy = ncopy / 10;
		len++;
	}
	str = numtostr(n, len + 1);
	return (str);
}

unsigned long long	ft_printf_get_unsigned_long(t_arg *arg)
{
	if (arg->length[0] == 'l' && arg->length[1] == 'l')
		return (va_arg(arg->ap, unsigned long long));
	else if (arg->length[0] == 'l')
		return ((unsigned long long)va_arg(arg->ap, unsigned long));
	else if (arg->length[0] == 'h' && arg->length[1] == 'h')
		return ((unsigned char)va_arg(arg->ap, unsigned int));
	else if (arg->length[0] == 'h')
		return ((unsigned short int)va_arg(arg->ap, unsigned int));
	else if (arg->length[0] == 'j')
		return ((unsigned long long)va_arg(arg->ap, unsigned long long));
	else if (arg->length[0] == 'z')
		return ((unsigned long long)va_arg(arg->ap, size_t));
	return (va_arg(arg->ap, unsigned int));
}
