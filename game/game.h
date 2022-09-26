/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:43:07 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/26 05:12:56 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include "../map/map.h"

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

int		open_game(t_game *game, int rows, int cols);

void	create_game(t_game *game, t_map *map);

#endif
