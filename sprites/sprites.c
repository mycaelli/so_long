#include "../map/map.h"
#include "../game/game.h"
#include "sprites.h"

// void	*mlx_new_image(void *mlx_ptr,int width,int height);
// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);


void img_generate(t_map *map, t_game *game)
{	
	//t_sprite **images;
	void *images[6];

	//t_sprite *wall;
	t_sprite *floor;
	/*t_sprite *collectible;
	t_sprite *door;
	t_sprite *character;*/

	//wall = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	floor = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	/*collectible = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	door = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	character = (t_sprite*) ft_calloc(1, sizeof(t_sprite));*/

	//if (!wall || !floor || !collectible || !door || !character) // correct error?
	if (!floor)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}

	//wall->path = "/home/coder/so_long/sprites/images/wall/wall.xpm";
	floor->path = "/home/coder/so_long/sprites/images/empty_space/floor.xpm";
	/*collectible->path = "/home/coder/so_long/sprites/images/empty_space/collectible.xpm";
	door->path = "/home/coder/so_long/sprites/images/exit/exit.xpm";
	character->path = "/home/coder/so_long/sprites/images/character/character.xpm";*/

	//wall->img = mlx_xpm_file_to_image(game->mlx_ptr, wall->path, &wall->width, &wall->height);
	floor->img = mlx_xpm_file_to_image(game->mlx_ptr, floor->path, &floor->width, &floor->height);
	/*collectible->img = mlx_xpm_file_to_image(game->mlx_ptr, collectible->path, &collectible->width, &collectible->height);
	door->img = mlx_xpm_file_to_image(game->mlx_ptr, door->path, &door->width, &door->height);
	character->img = mlx_xpm_file_to_image(game->mlx_ptr, character->path, &character->width, &character->height);*/

	//if  (!wall->img || !floor->img || !collectible->img || !door->img || !character->img)
	if (floor->img)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		printf("AQUI\n");
		exit (EXIT_FAILURE);
	} 
	//images[0] = wall->img;
	images[1] = floor->img;
	/*images[2] = collectible->img;
	images[3] = door->img;
	images[4] = character->img;*/
	put_sprites(map, game, images);
}

void	put_sprites(t_map *map, t_game *game, void *images[])
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
			//if (map->data[i][j] == '0')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[1], x * 31, y * 31);
			/*if (map->data[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[0], x * 31, y * 31);
			else if (map->data[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[2], x * 31, y * 31);
			else if (map->data[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[3], x * 31, y * 31);
			else if (map->data[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[4], x * 31, y * 31);*/
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
