/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:53:39 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/29 21:07:48 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	path_validation(t_map *map, int x, int y, int arguments[])
{
	int	i;
	int	j;

	i = arguments[0];
	j = arguments[1];
	if (map->map_aux[x][y] == '1')
		return (0);
	map->map_aux[x][y] = '1';
	if (x == i && y == j)
		return (1);
	if (path_validation(map, x + 1, y, arguments) == 1)
		return (1);
	else if (path_validation(map, x, y + 1, arguments) == 1)
		return (1);
	else if (path_validation(map, x - 1, y, arguments) == 1)
		return (1);
	else if (path_validation(map, x, y - 1, arguments) == 1)
		return (1);
	return (0);
}

void	map_normalize(t_map *map)
{
	int	i;
	int	j;

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

void	find_character(t_map *map)
{
	int	x;
	int	y;

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

int	find_items(t_map *map)
{
	int	arguments[2];

	arguments[0] = 0;
	while (arguments[0]++ < map->rows - 1)
	{
		arguments[1] = 0;
		while (arguments[1]++ < map->cols - 1)
		{
			if (map->map_aux[arguments[0]][arguments[1]] == 'C'
				|| map->map_aux[arguments[0]][arguments[1]] == 'E')
			{
				map_normalize(map);
				if (path_validation(map, map->old_pos_character[0],
						map->old_pos_character[1], arguments) == 0)
				{
					map_free(map);
					return (0);
				}
			}
		}
	}
	return (1);
}

void	map_free(t_map *map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < map->rows)
	{
		free(map->data[i]);
		free(map->map_aux[i]);
		i++;
	}
	free(map->data);
	free(map->map_aux);
	free(map);
}
