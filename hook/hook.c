#include "hook.h"

int	close_win(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
	{
		img_free(window);
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);	
		mlx_destroy_display(window->mlx_ptr);
		map_free(window->map);
		free(window->mlx_ptr);
		free(window);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

//int	move_left(int keysym, t_window *window)
//{
//	if (keysym == XK_A) // trocar por minusculo
//	{
//
//	}
//}
