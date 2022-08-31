#include "hook.h"

int	handle_no_event(void *data)
{
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_input(int keysym, t_window *window)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	return (0);
}