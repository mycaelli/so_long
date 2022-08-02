/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcerquei <mcerquei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:12 by mcerquei          #+#    #+#             */
/*   Updated: 2022/08/02 21:54:26 by mcerquei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/so_long.h"

// abrir janela (qual tamanho?)
int	open_window()
{
	// criando uma struct data
	t_data	data;
	
	// inicializa a lib MLX 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (-1); // ERROR
	
	// cria uma nov janela, retorna um ponteiro para a janela
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "Cat game"); //tamanho da janela?
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (-1); //ERROR
	}

	// loop sobre o ponteiro mlx
	mlx_loop(data.mlx_ptr);

	// mlx_init inicializa um display que precisa ser fechado
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return 0;
}
/*
void	draw_window(t_data data)
{
	mlx_xpm_to_image(data.mlx_ptr, )
}*/

int main()
{
	open_window();
} 