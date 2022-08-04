// cc -lX11 -lXext -lmlx -Wall -Wextra -Werror get_next_line/get_next_line_utils.c  get_next_line/get_next_line.c map.c && ./a.out ./maps_files/map_0.ber

#ifndef MAP_H

# define MAP_H

# include <stdio.h> // APAGAAAAR
# include <fcntl.h>

typedef struct s_map
{
	char	**map_game;
	int		fd;
	int		*sizes;
}	t_map;


#endif