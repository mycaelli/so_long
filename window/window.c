/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:12 by mcerquei          #+#    #+#             */
/*   Updated: 2022/09/12 01:17:23 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "window.h"

int	open_window(t_window *window, int rows, int cols)
{
	// inicial
// abrir janela (qual tamanho?)iza a lib MLX 
	window->mlx_ptr = mlx_init();
	//printf("%zu\n", window->rows);
	if (!window->mlx_ptr)
	{
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	window->cols = WIN_SIZE * cols;
	window->rows = WIN_SIZE * rows;
	// cria uma nov janela, retorna um ponteiro para a janela
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->rows, window->cols, "Cat window"); //tamanho da janela?
	if (!window->win_ptr)
	{
		free(window->win_ptr);
		ft_printf("Error\n %s\n", strerror(ENOMEM));
		exit (EXIT_FAILURE);
	}
	return 0;
}