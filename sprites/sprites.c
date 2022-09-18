#include "sprites.h"

void 	img_generate(t_window *window)
{	
	t_sprite *wall;
	t_sprite *floor;
	t_sprite *collectible;
	t_sprite *door;
	t_sprite *character;

	window->sprites = (void *) ft_calloc(5, sizeof(void *));
	wall = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	floor = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	collectible = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	door = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	character = (t_sprite*) ft_calloc(1, sizeof(t_sprite));
	
	if (!window->sprites || !wall || !floor || !collectible || !door || !character)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	wall->path = "/home/coder/so_long/sprites/images/wall/wall.xpm";
	floor->path = "/home/coder/so_long/sprites/images/floor/floor.xpm";
	collectible->path = "/home/coder/so_long/sprites/images/collectible/collectible.xpm";
	character->path = "/home/coder/so_long/sprites/images/character/character.xpm";
	door->path = "/home/coder/so_long/sprites/images/door/door.xpm";

	wall->img = mlx_xpm_file_to_image(window->mlx_ptr, wall->path, &wall->width, &wall->height);
	floor->img = mlx_xpm_file_to_image(window->mlx_ptr, floor->path, &floor->width, &floor->height);
	character->img = mlx_xpm_file_to_image(window->mlx_ptr, character->path, &character->width, &character->height);
	collectible->img = mlx_xpm_file_to_image(window->mlx_ptr, collectible->path, &collectible->width, &collectible->height);
	door->img = mlx_xpm_file_to_image(window->mlx_ptr, door->path, &door->width, &door->height);

	free(wall);
	free(floor);
	free(character);
	free(collectible);
	free(door);

	if (!wall->img || !floor->img || !character->img || !collectible->img || !door->img)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		printf("AQUI\n");
		exit (EXIT_FAILURE);
	} 
	window->sprites[WALL] = wall->img;
	window->sprites[FLOOR] = floor->img;
	window->sprites[COLLECTIBLE] = collectible->img;
	window->sprites[DOOR] = door->img;
	window->sprites[CHARACTER] = character->img;
	put_sprites(window);
}

void	put_sprites(t_window *window)
{
	int x;
	int y;

	x = 0;
	while (x < window->map->rows)
	{
		y = 0;
		while (y < window->map->cols)
		{
			if (window->map->data[x][y] == '0')
			{
				mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[FLOOR], x * 32, y * 32);
				//mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[DOOR], x * 32, y * 32);
			}
			else if (window->map->data[x][y] == '1')
				mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[WALL], x * 32, y * 32);
			else if (window->map->data[x][y] == 'P')
				mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[CHARACTER], x * 32, y * 32);
			else if (window->map->data[x][y] == 'C')
				mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[COLLECTIBLE], x * 32, y * 32);
			else if (window->map->data[x][y] == 'E')
				mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[DOOR], x * 32, y * 32);
			y++;
		}
		x++;
	}
}

void	img_free(t_window *window)
{
	mlx_destroy_image(window->mlx_ptr, window->sprites[WALL]);
	mlx_destroy_image(window->mlx_ptr, window->sprites[FLOOR]);
	mlx_destroy_image(window->mlx_ptr, window->sprites[COLLECTIBLE]);
	mlx_destroy_image(window->mlx_ptr, window->sprites[DOOR]);
	mlx_destroy_image(window->mlx_ptr, window->sprites[CHARACTER]);

	free(window->sprites);
}
