# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 21:20:54 by mcerquei          #+#    #+#              #
#    Updated: 2022/08/04 21:15:19 by mcerquei         ###   ########.fr        #
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
	


SRC = 	map.c

SRC_OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(SRC_OBJ)

$(SRC_OBJ):
	$(CC) $(CFLAGS) $(X_FLAGS) $(SRC_LIBFT) $(SRC_GNL) $(SRC) -L ./ -o $(NAME) 

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