/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/05 05:10:49 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/map.h"
#include "./includes/gnl.h"
#include "./libft/libft.h"

int	line_size(char *line);
t_map	*map_size(char *file_path, t_map *map);
char	**creat_map();

int	main(int argc, char *argv[])
{
	t_map *map;

	map = NULL;
	map = map_size(argv[1], map);
	printf("%d\n", map->rows);
	printf("%d\n", map->cols);	
	argc++; //ARRUMAR ISSOOOOOO
}

t_map	*map_size(char *file_path, t_map *map)
{
	char		*line;
	int			fd;

	map = (t_map*) ft_calloc(1, sizeof(t_map));
	map->rows = 0;
	map->cols = 0;
	fd = open(file_path, O_RDONLY); //verify fd
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
	return (map);
} 

/*
//create map 
// **game_map
	// game[0][0] = line[0]
char	**creat_map(t_map *map)
{
	//printf("%d\n", map->rows);

	map = ft_calloc(sizeof(t_map));

	printf("aqui\n"); 
	
	int i;

	i = 0;
	char **info = ft_calloc(sizeof(char*), map->rows);
	while (i < map->rows)
	{
		info[i] = ft_calloc(sizeof(char), map->cols);
	}
	map->data = info; 
	return (map->data);
}*/
