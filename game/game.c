/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:12 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/13 19:43:59 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"

// abrir janela (qual tamanho?)
int	open_window(t_game *game, int rows, int cols)
{
	// criando uma struct game

	// inicializa a lib MLX 
	game->mlx_ptr = mlx_init();
	game->rows = WIN_SIZE * rows;
	game->cols = WIN_SIZE * cols;
	//printf("%zu\n", game->rows);
	if (!game->mlx_ptr)
		return (-1); // ERROR
	
	// cria uma nov janela, retorna um ponteiro para a janela
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->rows, game->cols, "Cat game"); //tamanho da janela?
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		return (-1); //ERROR
	}

	// loop sobre o ponteiro mlx
	mlx_loop(game->mlx_ptr);

	// mlx_init inicializa um display que precisa ser fechado
	// TEM QUE VOLTAR ISSO DPS (NO MAIN?)
	//mlx_destroy_display(game->mlx_ptr);
	//free(game->mlx_ptr);
	return 0;
}