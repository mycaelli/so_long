#include "../map/map.h"
#include "../game/game.h"
#include "sprites.h"

void img_generate(t_map *map, t_game *game)
{	
	void *images[7];

	t_sprite *wall;
	t_sprite *floor;
	t_sprite *collectible;
	t_sprite *door;
	t_sprite *character;
	t_sprite *background;

	wall = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	floor = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	collectible = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	door = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	character = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	background = (t_sprite*) ft_calloc(1, sizeof(t_sprite));

	if (!wall || !floor || !collectible || !door || !character || !background)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	wall->path = "/home/coder/so_long/sprites/images/wall/wall.xpm";
	floor->path = "/home/coder/so_long/sprites/images/floor/floor_24_24.xpm";
	collectible->path = "/home/coder/so_long/sprites/images/collectible/pumpkin_24_24_certo.xpm";
	character->path = "/home/coder/so_long/sprites/images/character/ghost_bg.xpm";
	background->path =  "/home/coder/so_long/sprites/images/background/background.xpm";
	//door->path = "/home/coder/so_long/sprites/images/exit/AnyConv.com__door_ok.xpm";

	wall->img = mlx_xpm_file_to_image(game->mlx_ptr, wall->path, &wall->width, &wall->height);
	floor->img = mlx_xpm_file_to_image(game->mlx_ptr, floor->path, &floor->width, &floor->height);
	character->img = mlx_xpm_file_to_image(game->mlx_ptr, character->path, &character->width, &character->height);
	//collectible->img = mlx_xpm_file_to_image(game->mlx_ptr, collectible->path, &collectible->width, &collectible->height);
	//background->img = mlx_xpm_file_to_image(game->mlx_ptr, background->path, &background->width, &background->height);
	//door->img = mlx_xpm_file_to_image(game->mlx_ptr, door->path, &door->width, &door->height);

	if (!wall->img || !floor->img || !character->img)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		printf("AQUI\n");
		exit (EXIT_FAILURE);
	} 
	images[0] = wall->img;
	images[1] = floor->img;
	//images[2] = collectible->img;
	//images[3] = door->img;
	images[4] = character->img;
	//images[5] = door->img;
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
	
	while (i < map->cols)
	{
		y = 0;
		j = 0;
		while (j < map->rows)
		{
			if (map->data[j][i] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[1], x * 24, y * 24);
			else if (map->data[j][i] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[0], x * 24, y * 24);
			else if (map->data[j][i] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[4], x * 24, y * 24);
			//else if (map->data[j][i] == 'E')
				//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[3], x * 24, y * 24);
			//else if (map->data[i][j] == 'E')
				//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[5], x * 24, y * 24);
			//else if (map->data[i][j] == 'C')
				//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[2], x * 31, y * 31);
			//else if (map->data[i][j] == 'E')
				//mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[3], x * 31, y * 31);
					//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images[3], x * 24, y * 24);

			y++;
			j++;
		}
		x++;
		i++;
	}
}
