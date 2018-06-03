# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dphuntso <dphuntso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/06 19:24:32 by dphuntso          #+#    #+#              #
#    Updated: 2018/06/03 10:17:23 by dphuntso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = a.out 
NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_conversion.c ft_printf_d.c ft_printf_d_help.c \
		ft_printf_helper.c ft_printf_o.c ft_printf_p.c ft_printf_s.c \
		ft_printf_u.c ft_printf_unsigned_help.c ft_printf_x.c \
		ft_printf_solve.c helper.c main.c

LIB = libft/libft.a

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@cd libft && make
	@ar rc $(NAME) $(OBJS) libft/*.o
	@ranlib $(NAME) $(libft/libft.a)
	# @gcc $(FLAGS) $(LIB) $(SRC)
	# @mv a.out $(NAME)

clean:
	@cd libft && make clean
	@rm -rf $(OBJS) ft_printf.h.gch

fclean: clean
	@cd libft && make fclean
	@rm -rf $(NAME)

main:
	@rm -rf $(NAME)
	@rm -rf $(OBJS)
	@gcc $(FLAGS) $(LIB) $(SRC)
	@mv a.out $(NAME)

re : fclean all
