// cc -lX11 -lXext -lmlx -Wall -Wextra -Werror get_next_line/get_next_line_utils.c  get_next_line/get_next_line.c map.c && ./a.out ./maps_fi./maps_files/map_0.berles/map_0.ber

// ./so_long.out ./maps_files/map_0.ber

#ifndef MAP_H

# define MAP_H

# include <stdio.h> // APAGAAAAR
# include <fcntl.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include <stddef.h> //size_t ?
#include <mlx.h>
#include <string.h>
#include <errno.h>

typedef struct s_map
{
	char	**data;
	int		rows;
	int		cols;
}	t_map;

void	map_size(char *file_path, t_map *map);
void	map_initialize(t_map *map);
void	map_generate(char *file_path, t_map *map);
void	check_chars(char c, int *check);
void	check_valid_char(int *check);
void	check_walls(t_map *map);
void	map_size(char *file_path, t_map *map);
int		map_open(char*file_path);
void	map_free(t_map *map);

#endif