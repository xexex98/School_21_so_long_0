/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/27 18:50:40 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// чел хватит путать x и y в массивеывадфыжаыфафыавыфэоавжыфа

void	coin(t_mlx	*mlx)
{
	if (mlx->map_in_array[mlx->y][mlx->x] == 'C')
	{
		mlx->map_in_array[mlx->y][mlx->x] = '0';
		mlx->coins++;
	}
}

void	gexit(t_mlx *mlx)
{
	if (mlx->map_in_array[mlx->y][mlx->x] == 'E' && mlx->coins == mlx->all_coins)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		printf("You won, gg!\n");
		exit(0);
	}
	
}
void	move(t_mlx *mlx, int x, int y)
{
	if (mlx->map_in_array[mlx->y + y][mlx->x + x] != '1')
	{
		mlx->moves++;
		if (mlx->map_in_array[mlx->y][mlx->x] != 'E')
			mlx->map_in_array[mlx->y][mlx->x] = '0';
		mlx->y += y;
		mlx->x += x;
		coin(mlx);
		map_draw(mlx);
		printf("Moves: %i\n", mlx->moves);
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/P.xpm", &mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, mlx->x * PIXELS, mlx->y * PIXELS);
		gexit(mlx);
	}
}

int key_press_hook(int keycode, t_mlx *mlx)
{
	if (keycode == W)
		move(mlx, 0, -1);
	if (keycode == A)
		move(mlx, -1, 0);
	if (keycode == S)
		move(mlx, 0, 1);
	if (keycode == D)
		move(mlx, 1, 0);
	// if (keycode == ESC)
	// 	close_game(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	map_validity(&mlx, argc, argv[1]);
	init_mlx(&mlx);
	map_draw(&mlx);

	player_pos(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press_hook, &mlx);
	mlx_hook(mlx.win, 17, 1L << 2, close_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
