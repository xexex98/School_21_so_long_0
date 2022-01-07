/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:41 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/07 15:33:26 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_map(t_mlx *mlx)
{
	mlx->ee = 0;
	mlx->pp = 0;
	mlx->cc = 0;
	mlx->i = 0;
	mlx->j = 0;
	mlx->columns = 0;
	mlx->len = 0;
	mlx->lines = 1;
	mlx->line = NULL;
	mlx->fd = 0;
	mlx->map_in_array = NULL;
	mlx->x = 0;
	mlx->y = 0;
	mlx->coins = 0;
	mlx->all_coins = 0;
	mlx->moves = 0;
	mlx->eo = 0;
	mlx->time = 0;
	mlx->frame = 0;
}

void	map_top(t_mlx *mlx)
{
	mlx->i = 0;
	while (mlx->line[mlx->i] != '\n')
	{
		if (mlx->line[mlx->i] != '1')
			exit_error(4);
		mlx->i++;
	}
	free(mlx->line);
}

void	map_mid(t_mlx *mlx)
{
	mlx->i = 0;
	p_e_c_num(mlx);
	if (mlx->line[0] != '1' || mlx->line[mlx->columns - 1] != '1')
		exit_error(4);
	while (mlx->line[mlx->i])
	{
		if (mlx->line[mlx->i] != '1' && mlx->line[mlx->i] != '0'
			&& mlx->line[mlx->i] != 'P' && mlx->line[mlx->i] != 'E'
			&& mlx->line[mlx->i] != 'C' && mlx->line[mlx->i] != '\n'
			&& mlx->line[mlx->i] != 'K')
			exit_error(5);
		mlx->i++;
	}
	mlx->i = 0;
}

void	map_end(t_mlx *mlx)
{
	mlx->i = 0;
	while (mlx->line[mlx->i])
	{
		if (mlx->line[mlx->i] == '1')
			mlx->i++;
		else
			exit_error(4);
	}
	mlx->i = 0;
}

void	map_mid_end(t_mlx *mlx)
{
	mlx->line = get_next_line(mlx->fd);
	free(mlx->line);
	while ((mlx->line != NULL))
	{
		mlx->lines++;
		if (mlx->line[mlx->columns] == '\0')
			map_end(mlx);
		else if (mlx->line[mlx->columns] == '\n')
			map_mid(mlx);
		else
			exit_error(6);
		mlx->line = get_next_line(mlx->fd);
		free(mlx->line);
	}
}
