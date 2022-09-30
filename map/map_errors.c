/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:50:32 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/29 22:04:18 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_chars(char c, int *check)
{
	if (c == 'C')
		check[0]++;
	else if (c == 'E')
		check[1]++;
	else if (c == 'P')
		check[2]++;
	else if (c != '0' && c != '1' && c != '\n' && c)
		check[3]++;
}

void	check_valid_char(t_map *map, int *check)
{
	if (check[0] == 0 || check[1] == 0 || check[2] == 0)
	{
		ft_printf("Error\n");
		ft_printf("The map must contain at least 1 character C, E and P\n");
		map_free(map);
		free(check);
		exit(EXIT_FAILURE);
	}
	else if (check[3] > 0)
	{
		ft_printf("Error\n Invalid character on map\n");
		map_free(map);
		free(check);
		exit(EXIT_FAILURE);
	}
}

void	check_walls(t_map *map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map->data[i][j] == '1')
	{
		if (i == 0 && j < map->cols - 1)
			j++;
		else if (j == map->cols - 1 && i < map->rows - 1)
			i++;
		else if (i == map->rows - 1 && j > 0)
			j--;
		else if (j == 0 && i > 0)
			i--;
		if (i == 0 && j == 0)
			return ;
	}
	ft_printf("Error\n Map is not surrounded by walls (1's)\n");
	map_free(map);
	exit(EXIT_FAILURE);
}

void	check_rect(t_map *map)
{
	int i;
	int	j;
	int line_size;
	int	lines;

	i = 0;
	j = 0;
	line_size = 0;
	while (i < map->rows)
	{
		if (i == 0 && j < map->cols - 1)
		{
			line_size++;
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < map->rows)
	{
		lines = 0;
		while (j < map->cols)
		{
			lines++;
			j++;
		}
		if (lines != line_size)
		{
			ft_printf("%d\n %d\n", lines, line_size);
			ft_printf("Error\n Map is not rectangular\n");
			map_free(map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
