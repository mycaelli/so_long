#include "window/window.h"
#include "map/map.h"
#include "sprites/sprites.h"
#include "hook/hook.h"

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

	img_generate(map, window);

	mlx_loop_hook(window->mlx_ptr, &handle_no_event, &window);
	mlx_key_hook(window->win_ptr, &handle_input, &window);

	mlx_loop(window->mlx_ptr);

	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);

	printf("DEPOIS\n");
}


