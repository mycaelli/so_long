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

void	check_chars(char c, t_map *map)
{
	int	*check;
	int i;

	i = -1;
	while (i++ < 6)
		check[i] = -1;
	if (c == 0)
		check[0] = 0;
	else if (c == 1)
		check[1] = 0;
	else if (c == 'C')
		check[2] = 0;
	else if (c == 'E')
		check[3] = 0;
	else if (c == 'P')
		check[4] = 0;
	else
		check[5] = 0;
}

void	check_valid_char(int *check)
{
	if (check[2] == -1 || check[3] == -1 || check[4] == -1)
	{
		ft_printf("Error\n The map must contain at least 1 character C, E and P\n");
		exit(EXIT_FAILURE);
	}
	else if (check[5] > -1)
	{
		ft_printf("Error\n Invalid character: %c on map\n", check[5]);
		exit(EXIT_FAILURE);	
	}
}

void	check_rect(int row, int col)
{
	if (row == col)
	{
		ft_printf("Error\n The map must be rectangular\n");
		exit(EXIT_FAILURE);
	}
}

void	check_walls(t_map *map)
{
	int verify[2];

	verify[0] = 0; //i
	verify[1] = 0; //j
	while (map->data[verify[0]][verify[1]] == 1)
	{
		if (verify[1] != map->cols-1 && verify[1] != 0)
		{
			if (verify[0] == 0)
				verify[1]+=2;
			verify[1]--;
		}
		else 
		{
			if (verify[1] == map->cols-1)
				verify[0]+=2;
			verify[0]--;
		}
	}
	if (map->data[verify[0]][verify[1]]  != 1)
	{
		ft_printf("Error\n Map is not surrounded by walls (1's)\n");
		exit(EXIT_FAILURE);
	}
}
