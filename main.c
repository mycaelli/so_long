#include "game/game.h"
#include "map/map.h"
#include "sprites/sprites.h"

int main(int argc, char *argv[])
{	
	/*MAP*/
	t_map 	*map;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error\n %s\n", strerror(EINVAL));
		exit (EXIT_FAILURE);
	}

	map = (t_map*) ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	map_size(argv[1], map);
	map_initialize(map);
	map_generate(argv[1], map);
	/*MAP*/

	
	/*GAME*/
	t_game *game;
	game = (t_game*) ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	open_window(game, map->rows, map->cols);	

	img_generate(map, game);

	/*t_sprite *wall;
	wall = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	if (!wall) // correct error?
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	img_generate(game, wall);
	printf("%d\n", wall->height);*/

	mlx_loop(game->mlx_ptr);

	printf("DEPOIS\n");
}


