/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/05 07:34:00 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/map.h"
#include "./includes/gnl.h"
#include "./libft/libft.h"

void	map_size(char *file_path, t_map *map);
void	map_initialize(t_map *map);
void	map_generate(char *file_path, t_map *map);

int	main(int argc, char *argv[])
{
	t_map *map;

	map = (t_map*) ft_calloc(1, sizeof(t_map));
	if (!map)
		printf("MAP ALLOCATION FAILED");
	map_size(argv[1], map);
	map_initialize(map);
	map_generate(argv[1], map);

	argc++; //ARRUMAR ISSOOOOOO -> if argc == 1 NO VALID MAP WAS GIVEN

	return (0);
}

void	map_size(char *file_path, t_map *map)
{
	char		*line;
	int			fd;

	map->rows = 0;
	map->cols = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		printf("ERROR: FD INVALID");
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
