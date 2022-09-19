
#ifndef SPRITES_H

# define SPRITES_H

#include "../game/game.h"
#include "../map/map.h"

typedef struct s_sprite
{
	char	*path; 
	int		width;
	int		height;
	void	*img;
}	t_sprite;

#define WALL				0
#define FLOOR				1	
#define COLLECTIBLE			2
#define DOOR				3
#define CHARACTER			4


//void img_generate(t_map *map, t_game *game);
void 	img_generate(t_game *game);	
void	put_sprites(t_game *game);
void	img_free(t_game *game);


//void	create_walls(t_game *game, t_wall *wall);
//void	put_sprites(t_map *map, t_wall *wall, t_game *game);
// 3 3 3/4

// app mobile bank 
// 

#endif