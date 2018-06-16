MAKE = make -C
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = -I /includes

# directories
SRCS_DIR = ./
INCS_DIR = ./includes/
OBJS_DIR = ./objs/

FILES = ft_printf.c ft_printf_conversion.c ft_printf_d.c ft_printf_d_help.c \
		ft_printf_helper.c ft_printf_o.c ft_printf_p.c ft_printf_s.c \
		ft_printf_u.c ft_printf_unsigned_help.c ft_printf_x.c \
		ft_printf_solve.c helper.c ft_printf_conversion_percent.c

CFILES = $(patsubst %, $(SRCS_DIR)%, $(FILES))
OFILES = $(patsubst %.c, $(OBJS_DIR)%.o, $(FILES))

LIB = ./libft/
LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME)

$(NAME):
	$(LIBM)
	$(CC) $(FLAGS) -c -I$(INCS_DIR) $(CFILES)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) *.o
	ranlib $(NAME)
	mkdir $(OBJS_DIR)
	mv *.o $(OBJS_DIR)

clean:
	@$(LIBC)
	@/bin/rm -rf $(OBJS_DIR)

fclean: clean
	@$(LIBF)
	@/bin/rm -f $(NAME) *.a
	@/bin/rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)

main_flags:
	gcc main.c $(FLAGS) $(NAME) -I $(INCS_DIR)

main:
	gcc main.c $(NAME) -I $(INCS_DIR)

re: fclean all

# tell Make that they're not associated with files
.PHONY: all clean fclean re debug
