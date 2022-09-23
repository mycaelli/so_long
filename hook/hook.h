/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:40:18 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/22 02:28:18 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H

# define HOOK_H

# include "../game/game.h"
# include "../sprites/sprites.h"	
# include "../game/game.h"

# define XK_ESCAPE                        0xff1b
# define XK_A                             0x0061
# define XK_D                             0x0064
# define XK_W                             0x0077
# define XK_S                             0x0073 

int	close_win(t_game *game);
int		key_input(int key, t_game *game);
void	move_character(t_game *game);
char	find_wall(int key, t_game *game);
void	print_movements(t_game *game);

#endif