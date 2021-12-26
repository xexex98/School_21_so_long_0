/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/26 18:32:31 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_mlx *mlx)
{
	t_p	p;
	player_img(mlx);
	p.y += 1;
	p.x += 0;
}

void	left(t_mlx *mlx)
{
	t_p	p;

	player_img(mlx);
	p.y += 0;
	p.x -= 1;

}

void	down(t_mlx *mlx)
{
	t_p	p;

	player_img(mlx);
	p.y -= 1;
	p.x += 0;
}

void	right(t_mlx *mlx)
{
	t_p	p;

	player_img(mlx);
	p.y += 0;
	p.x += 1;
}

void player_img(t_mlx *mlx)
{
	t_p	p;

	// p.y = 0;
	// p.x = 0;
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/P.xpm", &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, p.x * PIXELS, p.y * PIXELS);
	printf("x = %i\n", p.x);
	printf("y = %i\n", p.y);
}



int key_press(int keycode, t_mlx *mlx)
{
	t_map	map;

	if (keycode == W)
		up(mlx);
	if (keycode == A)
		left(mlx);
	if (keycode == S)
		down(mlx);
	if (keycode == D)
		right(mlx);
	if (keycode == ESC)
		close_game(mlx);
	return (0);
}

// int	actions(t_mlx *mlx)
// {

// }

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_p		p;
	map_validity(&map, argc, argv[1]);
	init_mlx(&mlx, &map);
	map_draw(&map, &mlx);

	player_pos(&map);
	mlx_hook(mlx.win, 2, 1L << 0, key_press, &mlx);
	// mlx_loop_hook(mlx->mlx, actions, mlx);
	// actions(&mlx);
	
	mlx_loop(mlx.mlx);
	return (0);
}
