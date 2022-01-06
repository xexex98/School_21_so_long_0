/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:04:03 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/06 17:53:49 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_error(int error)
{
	if (error == 1)
		printf("Wrong P, E, C num!\n");
	if (error == 2)
		printf("Square map!\n");
	if (error == 3)
		printf ("No map file!\n");
	if (error == 4)
		printf("Wall error!\n");
	if (error == 5)
		printf("Undefined symbol!");
	if (error == 6)
		printf("Non-rectangular map!\n");
	if (error == 7)
		printf("Wrong map extension!\n");
	if (error == 8)
		printf("int_mlx_error!\n");
	if (error == 9)
		printf("Net kartinki: ");
	if (error == 10)
		printf("Add map name ./so_long 'map_name!'");
	if (error == 11)
		printf("map_checker error");
	exit(0);
}

int	close_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	free_map(mlx);
	printf("_B_B_\n");
	exit(EXIT_SUCCESS);
}

void	free_map(t_mlx *mlx)
{
	int	j;

	j = 0;
	while (j < mlx->lines)
	{
		free(mlx->map_in_array[j]);
		j++;
	}
	free(mlx->map_in_array);
}
