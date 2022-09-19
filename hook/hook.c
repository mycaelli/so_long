#include "hook.h"

int	key_input(int key, t_game *game)
{
	char find;
	
	find = find_wall(key, game);
	if (key == XK_Escape)
		close_win(game);
	else if (key == XK_a && find != 'L')
		game->map->new_pos_character[X]--;
	else if (key == XK_d && find != 'R')
		game->map->new_pos_character[X]++;
	else if (key == XK_w && find != 'U')
		game->map->new_pos_character[Y]--;
	else if (key == XK_s && find != 'D')
		game->map->new_pos_character[Y]++;
	move_character(game);
	return (0);
}

char	find_wall(int key, t_game *game)
{
	int wall_pos[2];

	wall_pos[X] = game->map->old_pos_character[X];
	wall_pos[Y] = game->map->old_pos_character[Y];
	if (key == XK_a)
	{
		if (game->map->data[wall_pos[X] - 1][wall_pos[Y]] == '1')
			return ('L');
	}
	else if (key == XK_d)
	{
		if (game->map->data[wall_pos[X] + 1][wall_pos[Y]] == '1')
			return ('R');
	}
	else if (key == XK_w)
	{
		if (game->map->data[wall_pos[X]][wall_pos[Y] - 1] == '1')
			return ('U');
	}
	else if (key == XK_s)
	{
		if (game->map->data[wall_pos[X]][wall_pos[Y] + 1] == '1')
			return ('D');
	}
	return ('0');
}

void	close_win(t_game *game)
{
		img_free(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);	
		mlx_destroy_display(game->mlx_ptr);
		map_free(game->map);
		free(game->mlx_ptr);
		free(game);
		exit(EXIT_SUCCESS);
}

void	move_character(t_game *game)
{
	int character_x;
	int character_y;
	int obj_x;
	int obj_y;


	character_x = game->map->new_pos_character[X];
	character_y = game->map->new_pos_character[Y];
	obj_x = game->map->old_pos_character[X];
	obj_y = game->map->old_pos_character[Y];
	if (game->map->data[character_x][character_y] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], character_x * 32, character_y * 32);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[FLOOR], obj_x * 32, obj_y * 32);
		game->collected++;
		print_movements(game);
	}
	else if (game->map->data[character_x][character_y] == '0')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], character_x * 32, character_y * 32);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[FLOOR], obj_x * 32, obj_y * 32);	
		print_movements(game);
	}
//	else if (game->map->data[character_x][character_y] == 'E')
//	{
//		if (game->map->collectibles == game->collected)
//			//END GAME
//		return ;
//	}
	game->map->old_pos_character[X] = game->map->new_pos_character[X];
	game->map->old_pos_character[Y] = game->map->new_pos_character[Y];
}

void	print_movements(t_game *game)
{
	game->movements++;
	ft_printf("Number of movements is: %d\n", game->movements);
}