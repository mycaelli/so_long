/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:28:07 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 17:41:52 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H

# define SPRITES_H

# include "../game/game.h"

# define WALL_PATH			"so_long/sprites/images/wall/wall.xpm"
# define FLOOR_PATH			"so_long/sprites/images/floor/floor.xpm"
# define COLLECTIBLE_PATH 	"so_long/sprites/images/colle/colle.xpm"
# define CHARACTER_PATH		"so_long/sprites/images/char/char.xpm"
# define DOOR_PATH			"so_long/sprites/images/door/door.xpm"

# define WALL				0
# define FLOOR				1	
# define COLLECT			2
# define DOOR				3
# define CHARACTER			4

void	img_generate(t_game *game);

int		put_sprites(t_game *game);

void	put_sprites2(t_game *game, int x, int y);

void	img_free(t_game *game);

#endif