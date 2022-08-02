CFLAGS = -Wall -Wextra -Werror -g3 -I.

CC = gcc

RM = rm -rf

SRC = 	get_next_line.c \
		get_next_line_utils.c \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \

SRC_OBJ = $(SRC:.c=.o)

all: run

run:	cmp
		./a.out

cmp:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=100 $(SRC) get_next_line.h get_next_line_bonus.h ./main.c

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) ./a

re:	fclean all

.PHONY: all clean fclean re
