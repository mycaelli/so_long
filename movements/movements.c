#include "movements.h"

void find_character(t_window*window)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < window->map->rows)
	{
		while (col < window->map->cols)
		{
			if (window->map->data[row][col] == 'P')
			{
				window->character_x = row;
				window->character_y = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	check_left(t_window *window)
{
	int	pos_y;
	int	pos_x;

	pos_y = window->character_y;
	pos_x = window->character_x - 1;
	if (window->map->data[pos_x][pos_y] == '1')
		return;
	else if (window->map->data[pos_x][pos_y] == 'C')
	{
		// destroy image?
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->sprites[4], pos_x * 32, pos_y * 32);
		window->collected++;
		// print move
		
	}
}
