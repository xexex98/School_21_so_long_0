/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/22 20:48:46 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		endian;
}				t_img;


void	map_draw(t_map *map, t_img *img, t_mlx *mlx)
{
	int	i = 0;
	int	j = 1;

	while (map->map_in_array[j][i] != '\0')
	{
		if (map->map_in_array[j][i] == '1')
		{
			img->img = mlx_xpm_file_to_image(mlx->mlx, "./image.xpm", &img->img_width, &img->img_height);
			mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, i * 30, j * 30);
		}
		if (map->map_in_array[j][i] == '0')
		{
			img->img = mlx_xpm_file_to_image(mlx->mlx, "./bg.xpm", &img->img_width, &img->img_height);
			mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, i * 30, j * 30);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;
	// t_map2	map2;

	// map = (t_map *)malloc(sizeof(t_map));
	// if (!map)
	// 	return (-1);
	init_map(&map);
	map_check_fin(&map, argc, argv[1]);
	// printf("%c", map->map_in_array[1][5]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	map_draw(&map, &img, &mlx);
	mlx_loop(mlx.mlx);
	// while (1)
		// ;
	return (0);
}

			// printf("%s", map->map_in_array[0]);
			// mlx.mlx = mlx_init();
			// mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
			// img.img = mlx_xpm_file_to_image(mlx.mlx, "./image.xpm", &img.img_width, &img.img_height);
			// int	i = 3;

			// while (i-- != 0)
			// {
				
			// 	// if (map->map_in_array[0][0] == '1')
			// 	// {
			// 		mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, i * 30, 30);
			// 	// }
			// 	// i++;
			// }
				// 

// int	key_hook(int keycode, t_mlx *mlx)
// {
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }