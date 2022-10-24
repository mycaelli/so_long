NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

X_FLAGS = -lX11 -lXext -lmlx

RM = rm -rf

SRC =   map/map.c map/map_path.c game/game.c map/map_errors.c sprites/sprites.c hook/hook.c hook/apply_hook.c main.c 

OBJ = $(SRC:%.c=%.o)

LIBFT_A = ./libft/libft.a

CLEAN_LIBFT = cd libft && make clean

FCLEAN_LIBFT = cd libft && make fclean

all: $(NAME)
	
$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -Llibmlx.a -lmlx $(LIBFT_A) $(X_FLAGS) -o $(NAME) -g

$(LIBFT_A):
	cd ./libft && make

clean:
	$(RM) $(OBJ)
	$(CLEAN_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(FCLEAN_LIBFT)

re:	fclean all

.PHONY: all clean fclean re