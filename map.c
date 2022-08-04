/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/04 17:51:30 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/map.h"
#include "./includes/gnl.h"

int	line_size(char *line);
int	*map_size(char *file_path);
char	**creat_map();

int	main(int argc, char *argv[])
{
	map_size(argv[1]);
	creat_map();

	argc++; //ARRUMAR ISSOOOOOO
	//printf("argc: %d\n", argc);	
}

int	*map_size(char *file_path)
{
	t_map		map;
	char		*line;

	map.sizes[0] = 0;
	map.sizes[1] = 0;
	map.fd = open(file_path, O_RDONLY); //verify fd
	line = get_next_line(map.fd, 1);
	while (line[map.sizes[0]] && line[map.sizes[0]] != '\n')
		map.sizes[0]++;
	while (line)
	{
		line = get_next_line(map.fd, 1);
		map.sizes[1]++;
	}
	//printf("%d\n", map.sizes[0]);
	//printf("%d\n", map.sizes[1]);
	return(map.sizes);
}

//create map 
// **game_map
	// game[0][0] = line[0]
char	**creat_map()
{
	t_map		map;
	char		*string;
	int			i;
	int			j;
	
	i = 0;
	j = 0;
	map.map_game = NULL;
	string = get_next_line(map.fd, 1);
	
	//map.map_game[i][j] = string[i]; error here se pa
	/*while (string != NULL) 
	{
		string = get_next_line(map.fd, 1);
		map.map_game[i][j] = string[i];
		printf("%c ", map.map_game[i][j]);
		printf("emtrou\n");
		i++;
		j++;
	}*/
	printf("aqui\n");
	return (map.map_game);
}