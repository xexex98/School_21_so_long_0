/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/28 18:12:37 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animathion(t_mlx *mlx)
{
	mlx->time++;
	if (mlx->time == 50)
	{
		mlx->frame++;
		mlx->time = 0;
	}
}

int	paste_img_2(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	animathion(mlx);
	while (mlx->map_in_array[j])
	{
		i = 0;
		while (mlx->map_in_array[j][i])
		{
			if (mlx->map_in_array[j][i] == 'K' && mlx->frame % 2 == 0)
				norm1(mlx, i, j);
			else if (mlx->map_in_array[j][i] == 'K')
				norm2(mlx, i, j);
			i++;
		}
		j++;
	}
	return (0);
}

void	norm1(t_mlx *mlx, int i, int j)
{
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/0.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
		i * PIXELS, j * PIXELS);
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/K.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
		i * PIXELS, j * PIXELS);
}

void	norm2(t_mlx *mlx, int i, int j)
{
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/0.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
		i * PIXELS, j * PIXELS);
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/Ko.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
		i * PIXELS, j * PIXELS);
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
	mlx_loop_hook(mlx.mlx, paste_img_2, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
