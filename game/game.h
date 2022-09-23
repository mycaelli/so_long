/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:43:07 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/19 04:44:42 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "../map/map.h"
# include <stdlib.h>
# include <stddef.h> //size_t ?
# include <mlx.h>
# include <string.h>
# include <errno.h>

# define WIN_SIZE	32

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
