/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_includes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:12:30 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/23 17:16:30 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

char	**map_in_array(char *name, t_map *map)
{
	char	**array;
	char	*linegnl;
	int		fd;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	array = (char **)malloc(map->lines * map->columns);
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

int	map_check_fin(t_map *map, int argc, char *argv)
{
	if (argc == 2)
	{
		if (map_checker(argv, map) == 1)
		{
			return (1);
		}
		else
		{
			printf ("Ne norm");
			return (0);
		}
	}
	else
	{
		ft_putstr("Add map name ./so_long 'map_name!'");
		return (0);
	}
}

void	paste_img(t_map *map, t_img *img, t_mlx *mlx, char	*imgname)
{
	int	fd;

	fd = open(imgname, O_RDONLY);
	if (fd > 0)
	{
		img->img = mlx_xpm_file_to_image(mlx->mlx, imgname,
				&img->img_width, &img->img_height);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img->img,
			map->i * PIXELS, map->j * PIXELS);
		close (fd);
	}
	else
		return ;
}

void	map_draw(t_map *map, t_img *img, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->columns * PIXELS,
			map->lines * PIXELS, "so_long");
	while (map->j < map->lines)
	{
		while (map->map_in_array[map->j][map->i] != '\0')
		{
			if (map->map_in_array[map->j][map->i] == '1')
				paste_img(map, img, mlx, "../img/1.xpm");
			if (map->map_in_array[map->j][map->i] == '0')
				paste_img(map, img, mlx, "../img/0.xpm");
			if (map->map_in_array[map->j][map->i] == 'C')
				paste_img(map, img, mlx, "../img/C.xpm");
			if (map->map_in_array[map->j][map->i] == 'P')
				paste_img(map, img, mlx, "../img/P.xpm");
			if (map->map_in_array[map->j][map->i] == 'E')
				paste_img(map, img, mlx, "../img/E.xpm");
			map->i++;
		}
		map->i = 0;
		map->j++;
	}
	map->j = 0;
}
