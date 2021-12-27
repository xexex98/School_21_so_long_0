/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:59:00 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/27 19:02:09 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (mlx->map_in_array[mlx->y][mlx->x] == 'E'
		&& mlx->coins == mlx->all_coins)
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
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/P.xpm",
				&mlx->img_width, &mlx->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
			mlx->x * PIXELS, mlx->y * PIXELS);
		gexit(mlx);
	}
}

int	key_press_hook(int keycode, t_mlx *mlx)
{
	if (keycode == W)
		move(mlx, 0, -1);
	if (keycode == A)
		move(mlx, -1, 0);
	if (keycode == S)
		move(mlx, 0, 1);
	if (keycode == D)
		move(mlx, 1, 0);
	if (keycode == ESC)
		close_game(mlx);
	return (0);
}
