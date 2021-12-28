/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:40 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/28 18:38:55 by mbarra           ###   ########.fr       */
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

void	paste_img(t_mlx *mlx, char	*imgname)
{
	int	fd;

	fd = open(imgname, O_RDONLY);
	if (fd < 0)
		exit_error(9);
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, imgname,
			&mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
		mlx->i * PIXELS, mlx->j * PIXELS);
	close (fd);
}

void	map_draw_2(t_mlx *mlx)
{
	if (mlx->map_in_array[mlx->j][mlx->i] == 'C')
	{
		paste_img(mlx, "../img/0.xpm");
		paste_img(mlx, "../img/C.xpm");
	}
	if (mlx->map_in_array[mlx->j][mlx->i] == 'P')
	{
		paste_img(mlx, "../img/0.xpm");
		paste_img(mlx, "../img/P.xpm");
	}
}

void	map_draw(t_mlx *mlx)
{
	while (mlx->j < mlx->lines)
	{
		while (mlx->map_in_array[mlx->j][mlx->i] != '\0')
		{
			if (mlx->map_in_array[mlx->j][mlx->i] == '1')
				paste_img(mlx, "../img/1.xpm");
			if (mlx->map_in_array[mlx->j][mlx->i] == '0')
				paste_img(mlx, "../img/0.xpm");
			if (mlx->map_in_array[mlx->j][mlx->i] == 'E')
			{
				paste_img(mlx, "../img/0.xpm");
				if (mlx->eo == 1)
					paste_img(mlx, "../img/Eo.xpm");
				else
					paste_img(mlx, "../img/E.xpm");
			}
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
