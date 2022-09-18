/*#include "movements.h"

void	move_left(t_window *window)
{
	int	pos_y;
	int	pos_x;

	pos_y = window->map->pos_char[0];
	pos_x = window->map->pos_char[1];
	if (window->map->data[pos_x][pos_y] == '1')
		return;
	else if (window->map->data[pos_x][pos_y] == 'C')
	{
		// destroy image?
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[CHARACTER], pos_x * 32, pos_y * 32);
		window->collected++;
	}
	else if (window->map->data[pos_x][pos_y] == '0')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[CHARACTER], pos_x * 32, pos_y * 32);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[FLOOR], (pos_x + 1) * 32, pos_y * 32);	
	}
}

void	move_right(t_window *window)
{
	int	pos_y;
	int	pos_x;

	pos_y = window->map->pos_char[0];
	pos_x = window->map->pos_char[1] + 1;
	if (window->map->data[pos_x][pos_y] == '1')
		return;
	else if (window->map->data[pos_x][pos_y] == 'C')
	{
		// destroy image?
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[CHARACTER], 2 * 32, 2 * 32);
		//window->map->data[pos_x][pos_y] = '0';
		//put_sprites(window);
		window->collected++;
		// print move
		
	}
	else if (window->map->data[pos_x][pos_y] == '0')
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[CHARACTER], pos_x * 32, pos_y * 32);
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[FLOOR], (pos_x - 1) * 32, pos_y * 32);	
	}
}*/