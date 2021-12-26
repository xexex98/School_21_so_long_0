/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:40 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/26 18:13:33 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

char	**map_in_array(char *mapf, t_map *map)
{
	char	**array;
	char	*linegnl;
	int		fd;
	int		i;

	i = 0;
	fd = open(mapf, O_RDONLY);
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

void	paste_img(t_map *map, t_mlx *mlx, char	*imgname)
{
	int	fd;

	fd = open(imgname, O_RDONLY);
	if (fd < 0)
		exit_error(9);
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, imgname,
			&mlx->img_width, &mlx->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img,
		map->i * PIXELS, map->j * PIXELS);
	close (fd);
}

void	map_draw(t_map *map, t_mlx *mlx)
{
	while (map->j < map->lines)
	{
		while (map->map_in_array[map->j][map->i] != '\0')
		{
			if (map->map_in_array[map->j][map->i] == '1')
				paste_img(map, mlx, "../img/1.xpm");
			if (map->map_in_array[map->j][map->i] == '0')
				paste_img(map, mlx, "../img/0.xpm");
			if (map->map_in_array[map->j][map->i] == 'C')
				paste_img(map, mlx, "../img/C.xpm");
			if (map->map_in_array[map->j][map->i] == 'P')
				paste_img(map, mlx, "../img/P.xpm");
			if (map->map_in_array[map->j][map->i] == 'E')
				paste_img(map, mlx, "../img/E.xpm");
			map->i++;
		}
		map->i = 0;
		map->j++;
	}
	map->j = 0;
}

void	player_pos(t_map *map)
{
	t_p	p;

	while (map->j < map->lines)
	{
		map->i = 0;
		while (map->map_in_array[map->j][map->i] != '\0')
		{
			if (map->map_in_array[map->j][map->i] == 'P')
			{
				p.x = map->i;
				p.y = map->j;
			}
			map->i++;
		}
		map->i = 0;
		map->j++;
	}
	map->j = 0;
}

void init_mlx(t_mlx *mlx, t_map *map)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		exit_error(8);
	mlx->win = mlx_new_window(mlx->mlx, map->columns * PIXELS,
	map->lines * PIXELS, "so_long");
}