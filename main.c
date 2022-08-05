#include "./map/map.h"
#include "./includes/gnl.h"
#include "./libft/libft.h"
#include "./includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_map *map;

	map = (t_map*) ft_calloc(1, sizeof(t_map));
	if (!map)
		printf("MAP ALLOCATION FAILED");
	map_size(argv[1], map);
	map_initialize(map);
	map_generate(argv[1], map);

	// ver como dar free na struct
	//free(map->data);
	//free(map);
	argc++; //ARRUMAR ISSOOOOOO -> if argc == 1 NO VALID MAP WAS GIVEN

	return (0);
}

