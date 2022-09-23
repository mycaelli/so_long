/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:41:01 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/19 04:42:56 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	open_game(t_game *game, int rows, int cols)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	game->cols = WIN_SIZE * cols;
	game->rows = WIN_SIZE * rows;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->rows, game->cols, "Ghost & Pumpikins");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	return (0);
}
