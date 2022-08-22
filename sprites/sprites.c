#include "../map/map.h"
#include "../game/game.h"
#include "sprites.h"

// void	*mlx_new_image(void *mlx_ptr,int width,int height);
// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);


void img_generate(t_map *map, t_game *game)
{	
	t_sprite *wall;
	wall = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	if (!wall) // correct error?
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	wall->path = "/home/coder/so_long/sprites/images/wall/wall.xpm";
	wall->img = mlx_xpm_file_to_image(game->mlx_ptr, wall->path, &wall->width, &wall->height);
	if (!wall->img)
	{
		printf("IMG NULL\n");
		exit (EXIT_FAILURE);
	}
	put_sprites(map, game, wall);

	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	//sprite->img = mlx_new_image(game->mlx_ptr, sprite->width, sprite->height);
	//if (!sprite->img) // correct error?
	//{
	//	ft_printf("Error\n Image creation failed\n");
	//	exit (EXIT_FAILURE);
	//}
	/*sprite->img = mlx_xpm_file_to_image(game->mlx_ptr, sprite->file_path, &sprite->width, &sprite->height);
	if (!sprite->img) // correct error?
	{
		ft_printf("AQUI Error\n Image creation failed\n");
		exit (EXIT_FAILURE);
	}*/

	// 
}

void	put_sprites(t_map *map, t_game *game, t_sprite *sprite)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	while (i < map->rows)
	{
		y = 0;
		j = 0;
		//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->img, x * 30, y * 30);
		while (j < map->cols)
		{
			if (map->data[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->img, x * 31, y * 31);
				//printf("TÁ AQUI");
			}
			y++;
			j++;
		}
		x++;
		i++;
	}
	/*
	while (i < game->rows)
	{
		y = 12;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->img, x, y);
		while (j < game->cols)
		{	
			//if (map->data[x][y] == '1')
			//{
				//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->img, x, y);
			//}
			j++;
		}
		i++;
	}*/


/*	int i;
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
	}*/
}
