#include "window/window.h"
#include "map/map.h"
#include "sprites/sprites.h"
#include "hook/hook.h"
#include "movements/movements.h"

int main(int argc, char *argv[])
{	
	/*MAP*/
	t_map 	*map;
	int		i;

	i = 0;
	if (argc != 2)
	{
		ft_printf("Error\n %s\n", strerror(EINVAL));
		exit (EXIT_FAILURE);
	}

	map = (t_map*) ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	map_size(argv[1], map);
	map_initialize(map);
	map_generate(argv[1], map);
	/*MAP*/


	/*GAME*/
	t_window *window;
	window = (t_window*) ft_calloc(1, sizeof(t_window));
	if (!window)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	open_window(window, map->rows, map->cols);
	window->map = map;
	find_character(window);

	img_generate(map, window);
	/*GAME*/
	
	mlx_hook(window->win_ptr, 2, 1L<<0, close_win, window);
	//key_hook(int keycode,void *param);

	mlx_loop(window->mlx_ptr);
}


