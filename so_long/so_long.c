/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:25:59 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/27 19:02:58 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// чел хватит путать x и y в массивеывадфыжаыфафыавыфэоавжыфа
#include "so_long.h"

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
