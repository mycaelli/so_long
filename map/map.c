/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/07 19:02:35 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "map.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

void	map_size(char *file_path, t_map *map)
{
	char		*line;
	int			fd;

	map->rows = 0;
	map->cols = 0;
	fd = open(file_path, O_RDONLY); //CLOSE FILES
	if (fd < 0)
	{
		ft_printf("Error\n %s\n", strerror(ENOENT));
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd, 1);
	while (line[map->cols] && line[map->cols] != '\n')
		map->cols++;
	while (line)
	{
		line = get_next_line(fd, 1);
		map->rows++;
	}
	check_rect(map->rows, map->cols);
}

void	map_initialize(t_map *map)
{
	int i;
	
	i = -1;
	map->data = ft_calloc(sizeof(char*), map->rows);
	if (!map->data)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	while (i++ < map->rows)
		map->data[i] = ft_calloc(sizeof(char), map->cols);
	if (!*(map->data))
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
}

void	map_generate(char *file_path, t_map *map)
{
	char		*line;
	int			fd;
	int			i;
	int			j;
	int			count;

	i = 0;
	j = 0;
	count = map->rows;
	fd = open(file_path, O_RDONLY); // ja foi testado
	while (count)
	{
		line = get_next_line(fd, 1);
		j = -1;
		while (j++ < map->cols)
		{
			map->data[i][j] = line[j];
			check_chars(line[j], count);
		}
		i++;
		count--;
	}
	check_walls(map);
}
