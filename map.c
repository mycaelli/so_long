/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/04 21:25:05 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/map.h"
#include "./includes/gnl.h"
#include "./libft/libft.h"

int	line_size(char *line);
t_map	*map_size(char *file_path);
char	**creat_map();

int	main(int argc, char *argv[])
{
	creat_map(map_size(argv[1]));

	argc++; //ARRUMAR ISSOOOOOO
	//printf("argc: %d\n", argc);	
}
/*
int	*map_size(char *file_path)
{
	t_map		map;
	char		*line;
	int			fd;

	map.sizes[0] = 0;
	map.sizes[1] = 0;
	fd = open(file_path, O_RDONLY); //verify fd
	line = get_next_line(map.fd, 1);
	while (line[map.sizes[0]] && line[map.sizes[0]] != '\n')
		map.sizes[0]++;
	while (line)
	{
		line = get_next_line(fd, 1);
		map.sizes[1]++;
	}
	//printf("%d\n", map.sizes[0]);
	//printf("%d\n", map.sizes[1]);
	return(map.sizes);
} */

t_map	*map_size(char *file_path)
{
	t_map		*map;
	char		*line;
	int			fd;

	//map = ft_calloc(1, sizeof(t_map)); //ver como faz isso
	//map = ft_calloc(sizeof(t_map), 1);
	map->rows= 0;
	map->cols = 0;
	fd = open(file_path, O_RDONLY); //verify fd
	line = get_next_line(fd, 1);
	while (line[map->rows] && line[map->rows] != '\n')
		map->rows++;
	while (line)
	{
		line = get_next_line(fd, 1);
		map->cols++;
	}
	printf("%d\n", map->rows);
	printf("%d\n", map->cols);

	return (map);
} 

//create map 
// **game_map
	// game[0][0] = line[0]
char	**creat_map(t_map *map)
{
	//printf("%d\n", map->rows);
/*
	map = ft_calloc(sizeof(t_map));

	printf("aqui\n"); */
	return (map->map_game);
}