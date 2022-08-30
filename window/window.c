/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:12 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/30 04:41:47 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "window.h"

// abrir janela (qual tamanho?)
int	open_window(t_window *window, int rows, int cols)
{
	// criando uma struct window

	// inicializa a lib MLX 
	window->mlx_ptr = mlx_init();
	//printf("%zu\n", window->rows);
	if (!window->mlx_ptr)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	window->cols = WIN_SIZE * rows;
	window->rows = WIN_SIZE * cols;
	// cria uma nov janela, retorna um ponteiro para a janela
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->rows, window->cols, "Cat window"); //tamanho da janela?
	if (!window->win_ptr)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	// loop sobre o ponteiro mlx
	// mlx_init inicializa um display que precisa ser fechado
	// TEM QUE VOLTAR ISSO DPS (NO MAIN?)
	//mlx_destroy_display(window->mlx_ptr);
	//free(window->mlx_ptr);
	return 0;
}