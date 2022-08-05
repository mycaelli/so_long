/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/05 20:45:41 by mcerquei         ###   ########.fr       */
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
		ft_printf("Error\n %s\n", strerror(ENOENT));
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
	
	i = -1;
	map->data = ft_calloc(sizeof(char*), map->rows);
	if (!map->data)
		printf("ERROR: MAP->DATA CALLOC FAILED 1");
	while (i++ < map->rows)
		map->data[i] = ft_calloc(sizeof(char), map->cols);
	if (!*(map->data))
		printf("ERROR: MAP->DATA CALLOC FAILED 2");
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
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		printf("ERROR: FD INVALID");
	// Tentar fazer verificação dos erros aqui
	while (count)
	{
		line = get_next_line(fd, 1);
		j = -1;
		while (j++ < map->cols)
			map->data[i][j] = line[j];
		i++;
		count--;
	}
}
