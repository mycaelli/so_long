/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:33:19 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 02:19:06 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

char	find_wall(int key, t_game *game)
{
	int	wall_pos[2];

	wall_pos[X] = game->map->old_pos_character[X];
	wall_pos[Y] = game->map->old_pos_character[Y];
	if (key == XK_W)
	{
		if (game->map->data[wall_pos[X] - 1][wall_pos[Y]] == '1')
			return ('L');
	}
	else if (key == XK_S)
	{
		if (game->map->data[wall_pos[X] + 1][wall_pos[Y]] == '1')
			return ('R');
	}
	else if (key == XK_A)
	{
		if (game->map->data[wall_pos[X]][wall_pos[Y] - 1] == '1')
			return ('U');
	}
	else if (key == XK_D)
	{
		if (game->map->data[wall_pos[X]][wall_pos[Y] + 1] == '1')
			return ('D');
	}
	return ('0');
}

int	key_input(int key, t_game *game)
{
	char	find;

	find = find_wall(key, game);
	if (key != XK_ESCAPE && key != XK_A && key != XK_D
		&& key != XK_W && key != XK_S)
		return (0);
	if (key == XK_ESCAPE)
		close_win(game);
	else if (key == XK_W && find != 'L')
		game->map->new_pos_character[X]--;
	else if (key == XK_S && find != 'R')
		game->map->new_pos_character[X]++;
	else if (key == XK_A && find != 'U')
		game->map->new_pos_character[Y]--;
	else if (key == XK_D && find != 'D')
		game->map->new_pos_character[Y]++;
	if (find == '0')
		move_character(game);
	return (0);
}

void	invalid_path(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map_aux[i]);
		i++;
	}
	free(map->map_aux);
	free(map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
	exit(EXIT_SUCCESS);
}