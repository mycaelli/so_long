/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:28:07 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/23 22:34:41 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H

# define SPRITES_H

# include "../game/game.h"
# include "../map/map.h"

typedef struct s_sprite
{
	char	*path;
	int		width;
	int		height;
	void	*img;
}	t_sprite;

# define WALL				0
# define FLOOR				1	
# define COLLECTIBLE		2
# define DOOR				3
# define CHARACTER			4

void		img_generate(t_game *game);
int	put_sprites(t_game *game);
void	img_free(t_game *game);

#endif