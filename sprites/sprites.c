/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:26:04 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 17:33:43 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

#include "sprites.h"

void	img_generate(t_game *game)
{	
	int	size[10];

	game->sprites = (void *) ft_calloc(5, sizeof(void *));
	if (!game->sprites)
	{
		ft_printf("!game->sprites memory error");
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	game->sprites[WALL] = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/images/wall/wall.xpm", &size[0], &size[1]);
	game->sprites[FLOOR] = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/images/floor/floor.xpm", &size[2], &size[3]);
	game->sprites[COLLECT] = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/images/colle/colle.xpm", &size[4], &size[5]);
	game->sprites[CHARACTER] = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/images/char/char.xpm", &size[6], &size[7]);
	game->sprites[DOOR] = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/images/door/door.xpm", &size[8], &size[9]);
	if (!game->sprites[WALL] || !game->sprites[FLOOR] || !game->sprites[COLLECT]
		|| !game->sprites[CHARACTER] || !game->sprites[DOOR])
	{
		ft_printf("!game->sprites[SPRITE] memory error\n");
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	put_sprites(game);
}

int	put_sprites(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->rows)
	{
		y = 0;
		while (y < game->map->cols)
		{
			put_sprites2(game, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

void	put_sprites2(t_game *game, int x, int y)
{
	if (game->map->data[x][y] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[FLOOR], y * 32, x * 32);
	else if (game->map->data[x][y] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[WALL], y * 32, x * 32);
	else if (game->map->data[x][y] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[CHARACTER], y * 32, x * 32);
	else if (game->map->data[x][y] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[COLLECT], y * 32, x * 32);
	else if (game->map->data[x][y] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprites[DOOR], y * 32, x * 32);
}

void	img_free(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->sprites[WALL]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[FLOOR]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[COLLECT]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[DOOR]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[CHARACTER]);
	free(game->sprites);
}
