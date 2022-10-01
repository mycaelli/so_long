/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:41:01 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 01:29:41 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	create_game(t_game *game, t_map *map)
{
	if (!game)
	{
		map_free(map);
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	open_game(game, map, map->rows, map->cols);
	game->map = map;
	game->movements = 0;
}

int	open_game(t_game *game, t_map *map, int rows, int cols)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		map_free(map);
		free(game);
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	game->cols = WIN_SIZE * cols;
	game->rows = WIN_SIZE * rows;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->cols, game->rows, "Pumpikim Obssession");
	if (!game->win_ptr)
	{
		map_free(map);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free(game);
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	return (0);
}
