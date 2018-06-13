/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:16:09 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/11 21:08:14 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf_check_flags(char ch)
{
	if (ch == '#')
		return (1);
	else if (ch == '0')
		return (1);
	else if (ch == '-')
		return (1);
	else if (ch == '+')
		return (1);
	else if (ch == ' ')
		return (1);
	else
		return (0);
}

int					ft_printf_is_conversions(char *str)
{
	int i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (CONVERSIONS[i])
	{
		if (CONVERSIONS[i++] == *str)
			return (i);
	}
	return (-1);
}

int					ft_printf_is_modifier(char ch)
{
	int		i;
	char	*str;

	str = "lhjz";
	i = 0;
	while (i < 4)
	{
		if (ch == str[i])
			return (1);
		i++;
	}
	return (0);
}

unsigned long long	ft_pow(unsigned long long nb, unsigned long long pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char				*ft_itoa_base(unsigned long long v, unsigned long long b)
{
	unsigned long long		i;
	char					*nbr;
	unsigned long long		neg;

	i = 1;
	neg = 0;
	while (ft_pow(b, i) - 1 < v)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (v % b) + (v % b > 9 ? 'A' - 10 : '0');
		v = v / b;
	}
	return (nbr);
}
