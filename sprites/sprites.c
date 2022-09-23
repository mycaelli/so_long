/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:26:04 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/23 22:35:17 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

void	img_generate(t_game *game)
{	
	t_sprite	*wall;
	t_sprite	*floor;
	t_sprite	*collectible;
	t_sprite	*door;
	t_sprite	*character;

	game->sprites = (void *) ft_calloc(5, sizeof(void *));
	wall = (t_sprite *) ft_calloc(1, sizeof(t_sprite));
	floor = (t_sprite *) ft_calloc(1, sizeof(t_sprite));
	collectible = (t_sprite *) ft_calloc(1, sizeof(t_sprite));
	door = (t_sprite *) ft_calloc(1, sizeof(t_sprite));
	character = (t_sprite *) ft_calloc(1, sizeof(t_sprite));
	if (!game->sprites || !wall || !floor || !collectible || !door || !character)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	wall->path = "/home/coder/so_long/sprites/images/wall/wall.xpm";
	floor->path = "/home/coder/so_long/sprites/images/floor/floor.xpm";
	collectible->path = "/home/coder/so_long/sprites/images/collectible/collectible.xpm";
	character->path = "/home/coder/so_long/sprites/images/character/character.xpm";
	door->path = "/home/coder/so_long/sprites/images/door/door.xpm";
	wall->img = mlx_xpm_file_to_image(game->mlx_ptr, wall->path,
			&wall->width, &wall->height);
	floor->img = mlx_xpm_file_to_image(game->mlx_ptr, floor->path,
			&floor->width, &floor->height);
	character->img = mlx_xpm_file_to_image(game->mlx_ptr, character->path,
			&character->width, &character->height);
	collectible->img = mlx_xpm_file_to_image(game->mlx_ptr, collectible->path,
			&collectible->width, &collectible->height);
	door->img = mlx_xpm_file_to_image(game->mlx_ptr, door->path,
			&door->width, &door->height);
	if (!wall->img || !floor->img || !character->img
		|| !collectible->img || !door->img)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	game->sprites[WALL] = wall->img;
	game->sprites[FLOOR] = floor->img;
	game->sprites[COLLECTIBLE] = collectible->img;
	game->sprites[DOOR] = door->img;
	game->sprites[CHARACTER] = character->img;
	free(wall);
	free(floor);
	free(character);
	free(collectible);
	free(door);
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
			if (game->map->data[x][y] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites[FLOOR], x * 32, y * 32);
			else if (game->map->data[x][y] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites[WALL], x * 32, y * 32);
			else if (game->map->data[x][y] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites[CHARACTER], x * 32, y * 32);
			else if (game->map->data[x][y] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites[COLLECTIBLE], x * 32, y * 32);
			else if (game->map->data[x][y] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->sprites[DOOR], x * 32, y * 32);
			y++;
		}
		x++;
	}
	return (0);
}

void	img_free(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->sprites[WALL]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[FLOOR]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[COLLECTIBLE]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[DOOR]);
	mlx_destroy_image(game->mlx_ptr, game->sprites[CHARACTER]);
	free(game->sprites);
}
