/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/20 15:38:31 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct	s_mlx
// {
// 	void	*mlx;
// 	void	*win;
// }				t_mlx;

// typedef	struct s_img
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_lenght;
// 	int		endian;
// }				t_img;

// int	key_hook(int keycode, t_mlx *mlx)
// {
// 	printf("Hello from key_hook!\n");
// }
// int	main(void)
// {
// 	t_mlx	mlx;
// 	t_img	img;
// 	void	*mlx_image;
// 	void	*image;

// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
// 	img.img = mlx_new_image(mlx.mlx, 400, 400);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
// 	mlx_pixel_put(mlx.mlx, mlx.win, 40, 40, 0x00FF0000);
// 	// mlx_key_hook(mlx.win, key_hook, &mlx);
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 50, 50);
// 	mlx_loop(mlx.mlx);
// }

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (map_checker(argv[1]) == 1)
			printf("Norm");
		else
			printf ("Ne norm");
	}
	else
	{
		ft_putstr("Add map name ./so_long 'map_name!'");
		return (0);
	}
	// while (1)
	// 	;
}
