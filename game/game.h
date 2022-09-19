#ifndef game_H

# define game_H //CHECAR TOODOOOOOOS

#include "../map/map.h"
//#include "../sprites/sprites.h"
#include <stdlib.h>
#include <stddef.h> //size_t ?
#include <mlx.h>
#include <string.h>
#include <errno.h>

#define WIN_SIZE	32

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	size_t	cols;
	size_t	rows;
	t_map	*map;
	void	**sprites;
	int		collected;
	int		movements;
}	t_game;

int	open_game(t_game *game, int rows, int cols);
#endif