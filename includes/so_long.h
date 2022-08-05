/*#include <stdlib.h>
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h> //APAGAAAAR */

// cc map.c -lX11 -lXext -lmlx && ./a.out ./maps_files/map_0.ber

// clear && cc -lX11 -lXext -lmlx -Wall -Wextra -Werror map.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c && ./a.out

#ifndef SO_LONG_H

# define SO_LONG_H


//# include "../teste.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h> // APAGAAAAR
# include <stdlib.h> // APAGAR SE PA
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
#include <string.h>
#include <errno.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;


#endif
