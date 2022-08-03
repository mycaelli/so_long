/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 05:42:21 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/03 21:41:13 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"
#include "./includes/map.h"
#include "./includes/gnl.h"

int	line_size(char *line);
void	map_size(char *file_path);

int	main(int argc, char *argv[])
{
	map_size(argv[1]);
	/*t_map		map;
	char		*line;

	map.fd = open(argv[1], O_RDONLY);
	line = get_next_line(map.fd, 1);
	map.l_size = line_size(line);
	printf("%d\n", map.l_size);
	map.c_size = 0;
	while (line)
	{
		line = get_next_line(map.fd, 1);
		map.c_size++;
	}
	printf("%d\n", map.c_size); */

	argc++;
	
}

void	map_size(char *file_path)
{
	t_map		map;
	char		*line;
	//int i;

	//i = 0;
	map.l_size = 0;
	map.c_size = 0;
	map.fd = open(file_path, O_RDONLY);
	line = get_next_line(map.fd, 1);
	while (line[map.l_size] && line[map.l_size] != '\n')
		map.l_size++;
	printf("%d\n", map.l_size);

	while (line)
	{
		line = get_next_line(map.fd, 1);
		map.c_size++;
	}
	printf("%d\n", map.c_size);

}
