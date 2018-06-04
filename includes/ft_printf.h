/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:58:04 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/03 23:19:19 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERSIONS "sSpdDioOuUxXcC%"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_arg
{
	int		ret;
	int		width;
	int		precision;
	char	*str;
	char	flag[5];
	char	length[3];
	va_list	ap;
}					t_arg;

/*
**	ft_printf_solve.c
*/

char				*ft_printf_solve(char *str, t_arg *arg);

/*
**	ft_printf_helper.c
*/

int					ft_printf_wstrlen(wchar_t *str);

int					ft_printf_putstr(int num, char *str);

int					ft_printf_putwstr(int num, wchar_t *str);

void				ft_printf_putchar(int num, char *format, t_arg *arg);

/*
**	ft_printf.c
*/

int					ft_printf(const char *format, ...);

/*
**	helper.c
*/

char				*ft_itoa_base(unsigned long long v, unsigned long long b);

int					ft_printf_check_flags(char ch);

int					ft_printf_is_conversions(char *str);

int					ft_printf_is_modifier(char ch);

/*
**	ft_printf_conversion.c
*/

char				*ft_printf_conversion(char *format, t_arg *arg);

/*
**	ft_printf_d.c
*/

void				ft_printf_conversion_d(t_arg *arg, char *format);

/*
**	ft_printf_d_help.c
*/

char				*ft_printf_d_itoa(long long n);

long long			ft_printf_get_long(t_arg *arg, char *format);

/*
**	ft_printf_s.c
*/

void				ft_printf_conversion_s(t_arg *arg, char *format);

/*
**ft_printf_unsigned_help.c
*/

char				*ft_printf_itoa(unsigned long long n);

unsigned long long	ft_printf_get_unsigned_long(t_arg *arg);

/*
**	ft_printf_o.c
*/

void				ft_printf_conversion_o(t_arg *arg);

/*
**	ft_printf_p.c
*/

void				ft_printf_conversion_p(t_arg *arg);

/*
**	ft_printf_u.c
*/

void				ft_printf_conversion_u(t_arg *arg);

/*
**	ft_printf_x.c
*/

void				ft_printf_conversion_x(t_arg *arg, char ch);

/*
**	ft_printf_conversion_percent.c
*/

void				ft_printf_conversion_percent(t_arg *arg);

#endif
