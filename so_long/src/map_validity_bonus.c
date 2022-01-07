/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:59:45 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/07 15:33:51 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_validity(t_mlx *mlx, int argc, char *mapf)
{
	if (argc == 2)
	{
		init_map(mlx);
		mlx->fd = open(mapf, O_RDONLY);
		if (mlx->fd < 0)
			exit_error(3);
		mlx->line = get_next_line(mlx->fd);
		mlx->len = ft_strlen(mlx->line);
		mlx->columns = mlx->len - 1;
		map_name(mapf);
		map_top(mlx);
		map_mid_end(mlx);
		map_pec_size(mlx);
		mlx->map_in_array = map_in_array(mapf, mlx);
	}
	else
		exit_error(7);
}

void	map_name(char	*name)
{
	int	i;
	int	len;

	len = ft_strlen(name);
	i = len - 3;
	if (name[i - 1] != '.' || name[i] != 'b' || name[i + 1] != 'e'
		|| name[i + 2] != 'r' || name[i + 3] != '\0')
		exit_error(7);
}

void	p_e_c_num(t_mlx *mlx)
{
	while (mlx->line[mlx->j])
	{
		if (mlx->line[mlx->j] == 'E')
			mlx->ee++;
		if (mlx->line[mlx->j] == 'P')
			mlx->pp++;
		if (mlx->line[mlx->j] == 'C')
			mlx->cc++;
		mlx->j++;
	}
	mlx->j = 0;
}

void	map_pec_size(t_mlx	*mlx)
{
	if (mlx->ee < 1 || mlx->pp != 1 || mlx->cc < 1)
		exit_error(1);
	if (mlx->len - 1 == mlx->lines)
		exit_error(2);
}

void	open_img(t_mlx *mlx)
{
	mlx->img1 = mlx_xpm_file_to_image(mlx->mlx, "../img/0.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx->img2 = mlx_xpm_file_to_image(mlx->mlx, "../img/1.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx->img3 = mlx_xpm_file_to_image(mlx->mlx, "../img/C.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx->img4 = mlx_xpm_file_to_image(mlx->mlx, "../img/E.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx->img5 = mlx_xpm_file_to_image(mlx->mlx, "../img/Eo.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx->img6 = mlx_xpm_file_to_image(mlx->mlx, "../img/K.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx->img7 = mlx_xpm_file_to_image(mlx->mlx, "../img/Ko.xpm",
			&mlx->img_width, &mlx->img_height);
	mlx->img8 = mlx_xpm_file_to_image(mlx->mlx, "../img/P.xpm",
			&mlx->img_width, &mlx->img_height);
}
