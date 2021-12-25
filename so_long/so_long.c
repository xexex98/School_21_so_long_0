/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/25 18:29:49 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int i = 0;


int	close_game(t_mlx	*mlx)
{
	//нужно еще фришить картинки и прочее
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}


void	up(t_mlx *mlx)
{
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/P.xpm", &mlx->img_width, &mlx->img_height);
	mlx_destroy_image(mlx->mlx, mlx->img);
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 30, 30);
	// mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/P.xpm", &mlx->img_width, &mlx->img_height);
	// mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 30 * i, 30);
	
	i++;
}

int key_press(int keycode, t_mlx *mlx)
{
	if (keycode == W)
		up(mlx);
	if (keycode == A)
		printf("hi");
	if (keycode == S)
		printf("hi");
	if (keycode == D)
		printf("hi");
	if (keycode == ESC)
		close_game(mlx);
	return (0);
}

int	actions(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_loop_hook(mlx->mlx, actions, mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_img	img;

	init_map(&map);
	if (map_check_fin(&map, argc, argv[1]) == 0)
		return (0);
	map_draw(&map, &img, &mlx);
	actions(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
