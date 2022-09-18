#ifndef WINDOW_H

# define WINDOW_H //CHECAR TOODOOOOOOS

#include "../map/map.h"
//#include "../sprites/sprites.h"
#include <stdlib.h>
#include <stddef.h> //size_t ?
#include <mlx.h>
#include <string.h>
#include <errno.h>

#define WIN_SIZE	32

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	cols;
	size_t	rows;
	t_map	*map;
	void	**sprites;
	int		collected;
}	t_window;

int	open_window(t_window *window, int rows, int cols);
#endif