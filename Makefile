# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 21:20:54 by mcerquei          #+#    #+#              #
#    Updated: 2022/08/05 19:10:57 by mcerquei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.out

CFLAGS = -Wall -Wextra -Werror

X_FLAGS = -lX11 -lXext -lmlx

CC = cc

RM = rm -rf

LIBFT = ft_calloc.c
LIBFT_DIR = libft/
SRC_LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT))

GNL = get_next_line.c get_next_line_utils.c
GNL_DIR = get_next_line/
SRC_GNL = $(addprefix $(GNL_DIR), $(GNL))

PRINTF = ft_printf_char.c ft_printf_str.c ft_printf.c
PRINTF_DIR = ft_printf/
SRC_PRINTF = $(addprefix $(PRINTF_DIR), $(PRINTF))

#MAP = map.c
#MAP_DIR = map/
#SRC_MAP = $(addprefix $(MAP_DIR), $(MAP))

SRC = map/map.c main.c

SRC_OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(SRC_OBJ)

$(SRC_OBJ):
	$(CC) $(CFLAGS) $(X_FLAGS) $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GNL) $(SRC) -L ./ -o $(NAME) 

run: cmp
	./a.out $(SRC_OBJ)

cmp: all
	$(CC) -g $(CFLAGS) $(SRC)

run_clean: clean fclean
	$(RM) ./so_long.out $(SRC_OBJ)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re