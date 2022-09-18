#include "hook.h"

int	key_input(int key, t_window *window)
{
	char find;
	
	find = find_wall(key, window);
	if (key == XK_Escape)
		close_win(window);
	else if (key == XK_a && find != 'L')
		window->map->new_pos_character[X]--;
	else if (key == XK_d && find != 'R')
		window->map->new_pos_character[X]++;
	else if (key == XK_w && find != 'U')
		window->map->new_pos_character[Y]--;
	else if (key == XK_s && find != 'D')
		window->map->new_pos_character[Y]++;
	move_character(window);
	return (0);
}

char	find_wall(int key, t_window *window)
{
	int wall_pos[2];

	wall_pos[X] = window->map->old_pos_character[X];
	wall_pos[Y] = window->map->old_pos_character[Y];
	if (key == XK_a)
	{
		if (window->map->data[wall_pos[X] - 1][wall_pos[Y]] == '1')
			return ('L');
	}
	else if (key == XK_d)
	{
		if (window->map->data[wall_pos[X] + 1][wall_pos[Y]] == '1')
			return ('R');
	}
	else if (key == XK_w)
	{
		if (window->map->data[wall_pos[X]][wall_pos[Y] - 1] == '1')
			return ('U');
	}
	else if (key == XK_s)
	{
		if (window->map->data[wall_pos[X]][wall_pos[Y] + 1] == '1')
			return ('D');
	}
	return ('0');
}

void	close_win(t_window *window)
{
		img_free(window);
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);	
		mlx_destroy_display(window->mlx_ptr);
		map_free(window->map);
		free(window->mlx_ptr);
		free(window);
		exit(EXIT_SUCCESS);
}

void	move_character(t_window *window)
{
	int character_x;
	int character_y;
	int obj_x;
	int obj_y;


	character_x = window->map->new_pos_character[X];
	character_y = window->map->new_pos_character[Y];
	obj_x = window->map->old_pos_character[X];
	obj_y = window->map->old_pos_character[Y];
	if (window->map->data[character_x][character_y] == 'C')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[CHARACTER], character_x * 32, character_y * 32);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[FLOOR], obj_x * 32, obj_y * 32);
		window->collected++;
		print_movements(window);
	}
	else if (window->map->data[character_x][character_y] == '0')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[CHARACTER], character_x * 32, character_y * 32);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[FLOOR], obj_x * 32, obj_y * 32);	
		print_movements(window);
	}
//	else if (window->map->data[character_x][character_y] == 'E')
//	{
//		if (window->map->collectibles == window->collected)
//			//END GAME
//		return ;
//	}
	window->map->old_pos_character[X] = window->map->new_pos_character[X];
	window->map->old_pos_character[Y] = window->map->new_pos_character[Y];
}

void	print_movements(t_window *window)
{
	window->movements++;
	ft_printf("Number of movements is: %d\n", window->movements);
}