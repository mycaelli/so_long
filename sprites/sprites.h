
#ifndef SPRITES_H

# define SPRITES_H

#include "../window/window.h"
# include "../map/map.h"


typedef struct s_sprite
{
	char	*path; //
	int		width;
	int		height;
	void	*img;
}	t_sprite;

void img_generate(t_map *map, t_window *window);
void	put_sprites(t_map *map, t_window *window, void *images[]);

//void	create_walls(t_game *game, t_wall *wall);
//void	put_sprites(t_map *map, t_wall *wall, t_game *game);
// 3 3 3/4

// app mobile bank 
// 

#endif