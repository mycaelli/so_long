NAME = so_long.out

CC = cc

# ACRESCENTAR AS OUTRAS FLAGS DE COMPILACAO!!!!!!!
CFLAGS = -Wall -Wextra -Werror

X_FLAGS = -lX11 -lXext -lmlx

RM = rm -rf

SRC =   map/map.c window/window.c movements/movements.c map/map_errors.c sprites/sprites.c hook/hook.c main.c 

OBJ = $(SRC:%.c=%.o)

LIBFT_A = ./libft/libft.a

CLEAN_LIBFT = cd libft && make clean

FCLEAN_LIBFT = cd libft && make fclean

$(NAME): $(OBJ)

# CHECAR SE MAKEFILE TA RELINKING

# ADD AS RULES QUE FALTAM

$(OBJ): $(LIBFT_A)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_A) $(X_FLAGS) -o $(NAME) -g

$(LIBFT_A):
	cd ./libft && make

clean:
	$(RM) $(OBJ)
	$(CLEAN_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(FCLEAN_LIBFT)
