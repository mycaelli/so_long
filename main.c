#include "./map/map.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./includes/so_long.h"
#include "./ft_printf/ft_printf.h"

int	main(int argc, char *argv[])
{
	t_map *map;

	if (argc != 2)
	{
		ft_printf("Error\n %s\n", strerror(EINVAL));
		exit (EXIT_FAILURE);
	}

	//ft_printf("FT PRINTF OK\n");
	map = (t_map*) ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	map_size(argv[1], map);
	map_initialize(map);
	map_generate(argv[1], map);

	// ver como dar free na struct
	//free(map->data);
	//free(map);
	//argc++; //ARRUMAR ISSOOOOOO -> if argc == 1 NO VALID MAP WAS GIVEN
	//argv[argc]++;

	return (0);
}

