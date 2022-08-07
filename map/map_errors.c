// The map must contain at least 1 exit, 1 collectible, 
	//and 1 starting position
// The map must be rectangular
// The map must be closed/surrounded by walls. If it’s not, the program must return
	//an error
// You don’t have to check if there’s a valid path in the map
// You must be able to parse any kind of map, as long as it respects the above rules.
//if ERROR: the program must exit in a clean way, and return "Error\n" followed by an explicit error message

#include "../includes/so_long.h"
#include "map.h"
#include "../ft_printf/ft_printf.h"

void check_chars(char c, int *check)
{
	if (c == 'C')
		check[0]++;
	else if (c == 'E')
		check[1]++;
	else if (c == 'P')
		check[2]++;
	else if (c != '0' && c != '1' && c != '\n' && c)
		check[3]++;
}

void	check_valid_char(int *check)
{
	if (check[0] == 0 || check[1] == 0 || check[2] == 0)
	{
		ft_printf("Error\n The map must contain at least 1 character C, E and P\n");
		exit(EXIT_FAILURE);
	}
	else if(check[3] > 0)
	{
		ft_printf("Error\n Invalid character on map\n");
		exit(EXIT_FAILURE);	
	}
}

void	check_walls(t_map *map)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (map->data[i][j] == '1')
	{
		// se estiver na primeira linha
		// incrementa enquanto j ate a ultima col
		if (i == 0 && j < map->cols-1)
			j++;
		// se estiver ultuma coluna
		// incrementa enquanto i ate ultima linha
		else if (j == map->cols-1 && i < map->rows-1)
			i++;
		// se estiver na ultima linha
		// decrementa enquanto ate a primeira col
		else if(i == map->rows-1 && j > 0)
			j--;
		// se estiver na primeira col
		// decrementa enquanto até a primeira linha
		else if (j == 0 && i > 0)
			i--;
		if (i == 0 && j == 0)
			return ;
	}
	if (map->data[i][j] != 'E' && map->data[i][j] != 'P' && map->data[i][j] != 'C'
		&& map->data[i][j] != '1' && map->data[i][j] != '0')
	{
		ft_printf("Error\n Map is not rectangular\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("Error\n Map is not surrounded by walls (1's)\n");
	exit(EXIT_FAILURE);
}
