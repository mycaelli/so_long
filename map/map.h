/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:05:00 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 01:41:21 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H

# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include <errno.h>
# include "../libft/libft.h"

# define X 0
# define Y 1

typedef struct s_map
{
	char	**data;
	char	**map_aux;
	int		rows;
	int		cols;
	int		old_pos_character[2];
	int		new_pos_character[2];
	int		collectibles;
}	t_map;

void	map_size(char *file_path, t_map *map);
void	map_initialize(t_map *map);
int	map_generate(char *file_path, t_map *map);
void	check_chars(char c, int *check);
void	check_valid_char(int *check);
void	check_walls(t_map *map);
void	map_size(char *file_path, t_map *map);
int		map_open(char*file_path);
void	map_free(t_map *map);
int	map_path(t_map *map, int x, int y, int i, int j);
void	find_character(t_map *map);
int find_items(t_map *map);
void	map_normalize (t_map *maṕ);

#endif