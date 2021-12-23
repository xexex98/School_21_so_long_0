/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/23 16:18:22 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;

	init_map(&map);
	if (map_check_fin(&map, argc, argv[1]) == 0)
		return (0);
	map_draw(&map, &img, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
