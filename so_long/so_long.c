/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/23 18:12:38 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(int argc, char **argv)
// {
// 	t_mlx	mlx;
// 	t_map	map;
// 	t_img	img;

// 	init_map(&map);
// 	if (map_check_fin(&map, argc, argv[1]) == 0)
// 		return (0);
// 	map_draw(&map, &img, &mlx);
// 	mlx_key_hook(mlx.win, paste_img, &mlx);
// 	mlx_loop(mlx.mlx);
// 	return (0);
// }

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		endian;
}				t_mlx;


int	press(int keycode, t_mlx *mlx)
{
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, "../img/P.xpm", &mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 30, 30);
}

void key_hook(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, press, &mlx);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "Hello world!");
	key_hook(&mlx);
	// mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
}
