#include "../map/map.h"
#include "../game/game.h"
#include "sprites.h"

// void	*mlx_new_image(void *mlx_ptr,int width,int height);
// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

void img_generate(t_game *game, t_sprite *sprite)
{
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	sprite->img = mlx_xpm_file_to_image(game->mlx_ptr, sprite->file_path, &sprite->width, &sprite->height);
}	

/*
void	create_walls(t_game *game, t_wall *wall)
{
	//mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height)

	wall->ptr_wall = mlx_new_image(game->mlx_ptr, 24, 24);
}

void	put_sprites(t_map *map, t_wall *wall, t_game *game)
{
	int i;
	int j;
	int x;
	int y;
	i = 0;
	//x = 12;
	y = 12;
	// primeira linha
	while (i < map->rows)
	{
		x = 12;
		j = 0;
		while (j < map->cols)
		{
			if (map->data[i][j] == '1')
			{
				// retorna inteiro
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, wall->ptr_wall, x, y);
			}
			x += 24;
			j++;
		}
		y += 24;
		i++;
	}
}
*/
// extrato no 