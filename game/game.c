/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:12 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/12 01:17:23 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"

int	open_game(t_game *game, int rows, int cols)
{
	// inicial
// abrir janela (qual tamanho?)iza a lib MLX 
	game->mlx_ptr = mlx_init();
	//printf("%zu\n", game->rows);
	if (!game->mlx_ptr)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	game->cols = WIN_SIZE * cols;
	game->rows = WIN_SIZE * rows;
	// cria uma nov janela, retorna um ponteiro para a janela
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->rows, game->cols, "Cat game"); //tamanho da janela?
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	return 0;
}