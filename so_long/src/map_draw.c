/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:40 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/07 15:47:10 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_in_array(char *mapf, t_mlx *mlx)
{
	char	**array;
	char	*linegnl;
	int		fd;
	int		i;

	i = 0;
	fd = open(mapf, O_RDONLY);
	array = (char **)malloc(mlx->lines * mlx->columns);
	linegnl = get_next_line(fd);
	array[i++] = linegnl;
	while (linegnl != NULL)
	{		
		linegnl = get_next_line(fd);
		array[i] = linegnl;
		i++;
	}
	close(fd);
	return (array);
}

void	map_draw_2(t_mlx *mlx)
{
	if (mlx->map_in_array[mlx->j][mlx->i] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img1,
			mlx->i * PIXELS, mlx->j * PIXELS);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img3,
			mlx->i * PIXELS, mlx->j * PIXELS);
	}
	if (mlx->map_in_array[mlx->j][mlx->i] == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img1,
			mlx->i * PIXELS, mlx->j * PIXELS);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img8,
			mlx->i * PIXELS, mlx->j * PIXELS);
	}
}

void	map_draw_3(t_mlx *mlx)
{
	if (mlx->map_in_array[mlx->j][mlx->i] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img2,
			mlx->i * PIXELS, mlx->j * PIXELS);
	if (mlx->map_in_array[mlx->j][mlx->i] == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img1,
			mlx->i * PIXELS, mlx->j * PIXELS);
	if (mlx->map_in_array[mlx->j][mlx->i] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img1,
			mlx->i * PIXELS, mlx->j * PIXELS);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img4,
			mlx->i * PIXELS, mlx->j * PIXELS);
	}
}

void	map_draw(t_mlx *mlx)
{
	while (mlx->j < mlx->lines)
	{
		while (mlx->map_in_array[mlx->j][mlx->i] != '\0')
		{
			map_draw_3(mlx);
			map_draw_2(mlx);
			mlx->i++;
		}
		mlx->i = 0;
		mlx->j++;
	}
	mlx->j = 0;
}

void	player_pos(t_mlx *mlx)
{
	while (mlx->j < mlx->lines)
	{
		mlx->i = 0;
		while (mlx->map_in_array[mlx->j][mlx->i] != '\0')
		{
			if (mlx->map_in_array[mlx->j][mlx->i] == 'C')
				mlx->all_coins++;
			if (mlx->map_in_array[mlx->j][mlx->i] == 'P')
			{
				mlx->x = mlx->i;
				mlx->y = mlx->j;
			}
			mlx->i++;
		}
		mlx->i = 0;
		mlx->j++;
	}
	mlx->j = 0;
}
