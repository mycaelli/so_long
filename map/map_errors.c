/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 03:50:32 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/19 03:56:00 by mcerquei         ###   ########.fr       */
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

void	check_valid_char(int *check)
{
	if (check[0] == 0 || check[1] == 0 || check[2] == 0)
	{
		ft_printf("Error\n");
		ft_printf("The map must contain at least 1 character C, E and P\\n");
		exit(EXIT_FAILURE);
	}
	else if (check[3] > 0)
	{
		ft_printf("Error\n Invalid character on map\n");
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
	if (map->data[i][j] != 'E' && map->data[i][j] != 'P' &&
	map->data[i][j] != 'C' && map->data[i][j] != '1' && map->data[i][j] != '0')
	{
		ft_printf("Error\n Map is not rectangular\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Error\n Map is not surrounded by walls (1's)\n");
	exit(EXIT_FAILURE);
}
