/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/29 20:59:53 by mcerquei         ###   ########.fr       */
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
	map->map_aux = ft_calloc(sizeof(char *), map->rows);
	if (!map->data || !map->map_aux)
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
	int			*check;

	line = NULL;
	map->collectibles = 0;
	fd = map_open(file_path);
	check = ft_calloc(4, sizeof(int));
	map_insertion(map, line, check, fd);
	check_valid_char(check);
	check_walls(map);
	free(check);
	line = get_next_line(fd, 1);
	free(line);
	return (1);
}

void	map_insertion(t_map *map, char	*line, int	*check, int fd)
{
	int	count;
	int	pos[2];

	count = map->rows;
	pos[0] = 0;
	pos[1] = 0;
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
}
