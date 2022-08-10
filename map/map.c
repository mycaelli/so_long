/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/11 00:01:31 by mcerquei         ###   ########.fr       */
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
}

void	map_initialize(t_map *map)
{
	int i;

	i = 0;
	map->data = ft_calloc(sizeof(char*), map->rows);
	if (!map->data)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	while (i < map->rows)
	{
		map->data[i] = ft_calloc(sizeof(char*), map->cols);
		i++;
	}
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
	int			pos[2];
	int			count;
	int			*check;

	pos[0] = 0;
	pos[1] = 0;
	count = map->rows;
	fd = open(file_path, O_RDONLY); // ja foi testado
	check = ft_calloc(4, sizeof(int));
	while (count)
	{
		line = get_next_line(fd, 1);
		pos[1] = -1;
		while (pos[1]++ < map->cols)
		{
			map->data[pos[0]][pos[1]] = line[pos[1]];
			printf("%c", map->data[pos[0]][pos[1]]);
			check_chars(line[pos[1]], check);
		}
		printf("\n");
		pos[0]++;
		count--;
	}
	check_valid_char(check);
	check_walls(map);
	free(check);
}
