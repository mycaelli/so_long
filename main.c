/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:43:11 by mcerquei          #+#    #+#             */
/*   Updated: 2022/10/01 22:31:17 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "map/map.h"
#include "hook/hook.h"

void	map_functions(t_map *map, char	*path)
{
	if (!map)
	{
		ft_printf("!map error");
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	map_size(path, map);
	map_initialize(map);
	map_generate(path, map);
	find_character(map);
	if (find_items(map) == 0)
	{
		map_free(map);
		ft_printf("Error\n Map doesnt have a valid path\n");
		exit(EXIT_FAILURE);
	}
}

void	game_functions(t_game *game, t_map *map)
{
	create_game(game, map);
	img_generate(game);
}

int	main(int argc, char *argv[])
{	
	t_map	*map;
	t_game	*game;

	map = (t_map *) ft_calloc(1, sizeof(t_map));
	if (argc != 2)
	{
		free(map);
		ft_printf("Error\n %s\n", strerror(EINVAL));
		exit (EXIT_FAILURE);
	}
	map_functions(map, argv[1]);
	game = (t_game *) ft_calloc(1, sizeof(t_game));
	game_functions(game, map);
	mlx_expose_hook(game->win_ptr, put_sprites, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_input, game);
	mlx_hook(game->win_ptr, 17, 0, close_win, game);
	mlx_loop(game->mlx_ptr);
}
