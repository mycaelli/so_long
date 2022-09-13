#include "hook.h"

int	close_win(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);	
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
		free(window);
		map_free(window->map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
