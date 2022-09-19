#include "game/game.h"
#include "map/map.h"
#include "sprites/sprites.h"
#include "hook/hook.h"
#include "movements/movements.h"

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
	open_game(game, map->rows, map->cols);
	game->map = map;
	game->movements = 0;

	img_generate(game);
	/*GAME*/
	mlx_hook(game->win_ptr, 2, 1L<<0, key_input, game);

	mlx_loop(game->mlx_ptr);
}


