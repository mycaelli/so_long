/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 02:19:09 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 02:19:10 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int	close_win(t_game *game)
{
	img_free(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	map_free(game->map);
	free(game->mlx_ptr);
	free(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	move_exit(t_game *game)
{
	if (game->map->collectibles == game->collected)
	{
		print_movements(game);
		ft_printf("GAME OVER\n CONGRATS!\n");
		close_win(game);
	}
	else
	{
		ft_printf("You must collect all pumpkins\n");
		game->map->new_pos_character[X] = game->map->old_pos_character[X];
		game->map->new_pos_character[Y] = game->map->old_pos_character[Y];
		return ;
	}
}

void	move_general(t_game *game)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	new_x = game->map->new_pos_character[X];
	new_y = game->map->new_pos_character[Y];
	old_x = game->map->old_pos_character[X];
	old_y = game->map->old_pos_character[Y];
	if (game->map->data[new_x][new_y] == 'C')
	{
		game->collected++;
		game->map->data[new_x][new_y] = '0';
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprites[CHARACTER], new_y * 32, new_x * 32);
		game->map->data[new_x][new_y] = 'P';
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprites[FLOOR], old_y * 32, old_x * 32);
		game->map->data[old_x][old_y] = '0';
	print_movements(game);
}

void	move_character(t_game *game)
{
	if (game->map->data[game->map->new_pos_character[X]]
		[game->map->new_pos_character[Y]] == 'E')
		move_exit(game);
	else
		move_general(game);
	game->map->old_pos_character[X] = game->map->new_pos_character[X];
	game->map->old_pos_character[Y] = game->map->new_pos_character[Y];
}

void	print_movements(t_game *game)
{
	game->movements++;
	ft_printf("Number of movements is: %d\n", game->movements);
}
