#include "hook.h"

int	key_input(int key, t_game *game)
{
	char find;
	
	find = find_wall(key, game);
	if (key != XK_Escape && key != XK_a && key != XK_d && key != XK_w && key != XK_s)
		return (0);
	if (key == XK_Escape)
		close_win(game);
	else if (key == XK_a && find != 'L')
		game->map->new_pos_character[X]--;
	else if (key == XK_d && find != 'R')
		game->map->new_pos_character[X]++;
	else if (key == XK_w && find != 'U')
		game->map->new_pos_character[Y]--;
	else if (key == XK_s && find != 'D')
		game->map->new_pos_character[Y]++;
	move_character(game);
	return (0);
}

char	find_wall(int key, t_game *game)
{
	int wall_pos[2];

	wall_pos[X] = game->map->old_pos_character[X];
	wall_pos[Y] = game->map->old_pos_character[Y];
	if (key == XK_a)
	{
		if (game->map->data[wall_pos[X] - 1][wall_pos[Y]] == '1')
			return ('L');
	}
	else if (key == XK_d)
	{
		if (game->map->data[wall_pos[X] + 1][wall_pos[Y]] == '1')
			return ('R');
	}
	else if (key == XK_w)
	{
		if (game->map->data[wall_pos[X]][wall_pos[Y] - 1] == '1')
			return ('U');
	}
	else if (key == XK_s)
	{
		if (game->map->data[wall_pos[X]][wall_pos[Y] + 1] == '1')
			return ('D');
	}
	return ('0');
}

void	close_win(t_game *game)
{
		img_free(game);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);	
		mlx_destroy_display(game->mlx_ptr);
		map_free(game->map);
		free(game->mlx_ptr);
		free(game);
		exit(EXIT_SUCCESS);
}

void	move_character(t_game *game)
{
	// CHARACTER DESAPARECE QUANDO TENTA ENTRAR NA PAREDE
		// MAS ELE SEGUE NA POS CERTA
			// QUANDO ESSE PROBLEMA OCORRE AS VEZES O NUMERO DE COLETADOS E COLETAVEIS NAO BATE
			// MESMO TENDO COLETADO TODAS AS ABOBORAS
	
	// CONTA COMO MOVIMENTO QUANDO EU CLICO EM QUALQUER TECLA

	int new_x;
	int new_y;
	int old_x;
	int old_y;

	new_x = game->map->new_pos_character[X];
	new_y = game->map->new_pos_character[Y];
	old_x = game->map->old_pos_character[X];
	old_y = game->map->old_pos_character[Y];

	if (game->map->data[new_x][new_y] == 'E')
	{
		if (game->map->collectibles == game->collected)
		{
			ft_printf("GAME OVER\n CONGRATS!\n");
			close_win(game);
		}
		else 
		{
			ft_printf("You must collect all pumpkins before going back home\n");
			game->map->new_pos_character[X] = game->map->old_pos_character[X];
			game->map->new_pos_character[Y] = game->map->old_pos_character[Y];
			return ;
		}
	}
	else
	{
		if (game->map->data[new_x][new_y] == 'C')
			game->collected++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], new_x * 32, new_y * 32);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[FLOOR], old_x * 32, old_y * 32);
		print_movements(game);
	}

	game->map->old_pos_character[X] = game->map->new_pos_character[X];
	game->map->old_pos_character[Y] = game->map->new_pos_character[Y];
}

	//if (game->map->data[new_x][new_y] == 'C')
	//{
	//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], new_x * 32, new_y * 32);
	//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[FLOOR], old_x * 32, old_y * 32);
	//	game->collected++;
	//}
	//else if (game->map->data[new_x][new_y] == '0')
	//{
	//	printf("AQUI\n");
	//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[CHARACTER], new_x * 32, new_y * 32);
	//	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprites[FLOOR], old_x * 32, old_y * 32);	
	//	print_movements(game);
	//} 
	//else if (game->map->data[new_x][new_y] == 'E')
	//{
	//	if (game->map->collectibles == game->collected)
	//	{
	//		ft_printf("GAME OVER\n CONGRATS!\n");
	//		close_win(game);
	//	}
	//	else 
	//	{
	//		ft_printf("You must collect all pumpkins before going back home\n");
	//		game->map->new_pos_character[X] = game->map->old_pos_character[X];
	//		game->map->new_pos_character[Y] = game->map->old_pos_character[Y];
	//		return ;
	//	}
	//}

void	print_movements(t_game *game)
{
	game->movements++;
	ft_printf("Number of movements is: %d\n", game->movements);
}