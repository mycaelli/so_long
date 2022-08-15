
#ifndef SPRITES_H

# define SPRITES_H

# include "../game/game.h"
# include "../map/map.h"
// void	*mlx_new_image(void *mlx_ptr,int width,int height);
// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

/*
#define PATH_BCAT	../images/character/back.xpm
#define PATH_FCAT	so_long/images/character/front.xpm
#define PATH_LCAT	so_long/images/character/left.xpm
#define PATH_RCAT	so_long/images/character/richt.xpm
#define PATH_FLOOR	so_long/images/empty space/floor.xpm
#define PATH_ENEMY  so_long/images/enemy/enemy.xpm
#define PATH_EXIT   so_long/images/exit/exit.xpm
#define PATH_WALL	so_long/images/wall/wall.xpm
#define PATH_COLLECTIBLE	so_long/images/collectible/collectible.xpm
*/


typedef struct s_sprite
{
	char	*file_path; //
	int		width;
	int		height;
	void	*img;
}	t_sprite;

void img_generate(t_game *game, t_sprite *sprite);

//void	create_walls(t_game *game, t_wall *wall);
//void	put_sprites(t_map *map, t_wall *wall, t_game *game);
// 3 3 3/4

// app mobile bank 
// 

#endif