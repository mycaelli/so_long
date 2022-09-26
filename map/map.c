/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 02:34:42 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	map_open(char*file_path)
{
	int			fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n %s\n", strerror(ENOENT));
		exit(EXIT_FAILURE);
	}	
	return (fd);
}

void	map_size(char *file_path, t_map *map)
{
	char		*line;
	int			fd;

	map->rows = 0;
	map->cols = 0;
	fd = map_open(file_path);
	line = get_next_line(fd, 1);
	while (line[map->cols] && line[map->cols] != '\n')
		map->cols++;
	free(line);
	while (line)
	{
		line = get_next_line(fd, 1);
		free(line);
		map->rows++;
	}
}

void	map_initialize(t_map *map)
{
	int	i;

	i = 0;
	map->data = ft_calloc(sizeof(char *), map->rows);
	map->map_aux =  ft_calloc(sizeof(char *), map->rows);
	if (!map->data)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	while (i < map->rows)
	{
		map->data[i] = ft_calloc(sizeof(char *), map->cols);
		map->map_aux[i] = ft_calloc(sizeof(char *), map->cols);
		i++;
	}
	if (!*(map->data))
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
}

int	map_generate(char *file_path, t_map *map)
{
	char		*line;
	int			fd;
	int			pos[2];
	int			count;
	int			*check;

	pos[0] = 0;
	pos[1] = 0;
	count = map->rows;
	map->collectibles = 0;
	fd = map_open(file_path);
	check = ft_calloc(4, sizeof(int));
	while (count)
	{
		line = get_next_line(fd, 1);
		pos[1] = -1;
		while (pos[1]++ < map->cols)
		{
			map->data[pos[0]][pos[1]] = line[pos[1]];
			map->map_aux[pos[0]][pos[1]] = line[pos[1]];
			check_chars(line[pos[1]], check);
		}
		free(line);
		pos[0]++;
		count--;
	}
	check_valid_char(check);
	check_walls(map);
	free(check);
	line = get_next_line(fd, 1);
	free(line);
	return (1);
}

void	map_free(t_map *map)
{
	int	k;

	k = 0;
	while (k < map->rows)
	{
		free(map->data[k]);
		free(map->map_aux[k]);
		k++;
	}
	free(map->data);
	free(map->map_aux);
	free(map);
}

void	map_normalize (t_map *map)
{
	int i;
	int j;
	
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->map_aux[i][j] = map->data[i][j];
			j++;
		}
		i++;
	}
}

int	map_path(t_map *map, int x, int y, int i, int j) 
{
	if (map->map_aux[x][y] == '1')
		return (0);
	map->map_aux[x][y] = '1';
	if(x == i && y == j)
		return (1);
	if (map_path(map, x + 1, y, i, j) == 1)
		return (1);
	else if (map_path(map, x, y + 1, i, j) == 1)
		return (1);
	else if (map_path(map, x - 1, y, i, j) == 1)
		return (1);
	else if (map_path(map, x, y - 1, i, j) == 1)
		return (1);
	return (0);
}

void	find_character(t_map *map)
{
	int x;
	int y;

	x = 1;
	while (x < map->rows - 1)
	{
		y = 1;
		while (y < map->cols)
		{
			if (map->map_aux[x][y] == 'P')
			{
				map->old_pos_character[0] = x;
				map->old_pos_character[1] = y;
				map->new_pos_character[0] = x;
				map->new_pos_character[1] = y;
			}
			if (map->map_aux[x][y] == 'C')
				map->collectibles++;
			y++;
		}
		x++;
	}
}

int find_items(t_map *map)
{

	int x;
	int y;

	x = 1;
	while (x < map->rows - 1)
	{
		y = 1;
		while (y < map->cols - 1)
		{
			if (map->map_aux[x][y] == 'C')
			{
				map_normalize(map);
				if (map_path(map, map->old_pos_character[0], map->old_pos_character[1], x, y) == 0)
				{
					map_free(map);
					return (0);
				}
			}
			if (map->map_aux[x][y] == 'E')
			{
				map_normalize(map);
				if (map_path(map, map->old_pos_character[0], map->old_pos_character[1], x, y) == 0)
				{
					map_free(map);
					return (0);
				}
			}
			y++;
		}
		x++;
	}
	return (1);
}