# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 21:20:54 by mcerquei          #+#    #+#              #
#    Updated: 2022/09/19 01:50:33 by mcerquei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I. -c

CC = gcc

AR = ar rcs

RM = rm -rf

SRC = 	ft_strlen.c \
		ft_calloc.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_printf.c \
		ft_printf_str.c \
		ft_printf_char.c \
		ft_printf_signed_int.c \
		ft_itoa.c \


SRC_OBJ = $(SRC:.c=.o)

$(NAME):	$(SRC_OBJ)
	$(AR) $(NAME) $(SRC_OBJ)

$(SRC_OBJ):
	$(CC) $(CFLAGS) $(SRC)

all: $(NAME)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re