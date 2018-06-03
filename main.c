/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:27:27 by dphuntso          #+#    #+#             */
/*   Updated: 2018/06/01 23:30:18 by dphuntso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		main(void)
{
	ft_printf("- -  -- -- - - - - -- - - - - - - -\n");
	ft_printf("  %%.2s will be -> %.2sover\n", "hello");
	ft_printf("%%-6.6s will be -> %2.5sover\n", "hello");
	ft_printf("- -- -- - - -- - - - -- - - - - - -\n");
	printf("- -  -- -- - - - - -- - - - - - - -\n");
	printf("  %%.2s will be -> %.2sover\n", "hello");
	printf("%%-6.6s will be -> %2.5sover\n", "hello");
	printf("- -- -- - - -- - - - -- - - - - - -\n");
	while (1)
		write(1, "", 1);
	return (1);
}
