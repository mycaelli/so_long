#include "map.h"

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
