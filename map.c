/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/05 06:40:06 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/map.h"
#include "./includes/gnl.h"
#include "./libft/libft.h"

int	line_size(char *line);
void	map_size(char *file_path, t_map *map);
void	initialize_map(t_map *map);
char	**creat_map();

int	main(int argc, char *argv[])
{
	t_map *map;

	map = (t_map*) ft_calloc(1, sizeof(t_map));
	if (!map)
		printf("MAP ALLOCATION FAILED");
	map_size(argv[1], map);
	initialize_map(map);
	printf("%d\n", map->rows);
	printf("%d\n", map->cols);
	argc++; //ARRUMAR ISSOOOOOO -> if argc == 1 NO VALID MAP WAS GIVEN
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
	while (line[map->rows] && line[map->rows] != '\n')
		map->rows++;
	while (line)
	{
		line = get_next_line(fd, 1);
		map->cols++;
	}
}

void	initialize_map(t_map *map)
{
	//char **info;
	int i;
	
	i = 0;
	//printf("%s\n", map->data);
	map->data = ft_calloc(sizeof(char*), map->rows);
	if (!map->data)
		printf("MAP->DATA CALLOC FAILED 1");

	while (i < map->rows)
	{
		map->data[i] = ft_calloc(sizeof(char), map->cols);
		i++;
	}
	if (!*(map->data))
		printf("MAP->DATA CALLOC FAILED 2");
}
