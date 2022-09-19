/*#include "movements.h"

void	move_left(t_game *game)
{
	int	pos_y;
	int	pos_x;

	pos_y = game->map->pos_char[0];
	pos_x = game->map->pos_char[1];
	if (game->map->data[pos_x][pos_y] == '1')
		return;
	else if (game->map->data[pos_x][pos_y] == 'C')
	{
		// destroy image?
		mlx_put_image_to_game(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], pos_x * 32, pos_y * 32);
		game->collected++;
	}
	else if (game->map->data[pos_x][pos_y] == '0')
	{
		mlx_put_image_to_game(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], pos_x * 32, pos_y * 32);
		mlx_put_image_to_game(game->mlx_ptr, game->win_ptr, game->sprites[FLOOR], (pos_x + 1) * 32, pos_y * 32);	
	}
}

void	move_right(t_game *game)
{
	int	pos_y;
	int	pos_x;

	pos_y = game->map->pos_char[0];
	pos_x = game->map->pos_char[1] + 1;
	if (game->map->data[pos_x][pos_y] == '1')
		return;
	else if (game->map->data[pos_x][pos_y] == 'C')
	{
		// destroy image?
		mlx_put_image_to_game(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], 2 * 32, 2 * 32);
		//game->map->data[pos_x][pos_y] = '0';
		//put_sprites(game);
		game->collected++;
		// print move
		
	}
	else if (game->map->data[pos_x][pos_y] == '0')
	{
		mlx_put_image_to_game(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], pos_x * 32, pos_y * 32);
		mlx_put_image_to_game(game->mlx_ptr, game->win_ptr, game->sprites[FLOOR], (pos_x - 1) * 32, pos_y * 32);	
	}
}*/