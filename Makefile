NAME = so_long.out

CC = cc

X_FLAGS = -lX11 -lXext -lmlx

RM = rm -rf

SRC =  map/map.c game/game.c map/map_errors.c sprites/sprites.c main.c 

OBJ = $(SRC:%.c=%.o)

LIBFT_A = ./libft/libft.a

CLEAN_LIBFT = cd libft && make clean

FCLEAN_LIBFT = cd libft && make fclean

$(NAME): $(OBJ)

$(OBJ): $(LIBFT_A)
	$(CC) $(SRC) $(LIBFT_A) $(X_FLAGS) -o $(NAME)

$(LIBFT_A):
	cd ./libft && make

clean:
	$(RM) $(OBJ)
	$(CLEAN_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(FCLEAN_LIBFT)


