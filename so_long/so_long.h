/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:26:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/26 18:32:02 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define PIXELS	40
# define A		0
# define S		1
# define D		2
# define W		13
# define ESC	53

typedef struct s_p
{
	int	x;
	int	y;
}				t_p;

typedef struct s_map
{
	int		ee;
	int		pp;
	int		cc;
	int		i;
	int		j;
	int		columns;
	int		len;
	int		lines;
	char	*line;
	int		fd;
	char	**map_in_array;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		endian;


}				t_mlx;


void	exit_error(int error);
int		close_game(t_mlx *mlx);

void	map_validity(t_map *map, int argc, char *mapf);
void	map_name(char	*name);
void	p_e_c_num(char	*line, t_map *map);
void	map_pec_size(t_map	*map);

t_map	*init_map(t_map *map);
void	map_top(char	*line, t_map *map);
void	map_mid(t_map *map);
void	map_end(t_map *map);
void	map_mid_end(char *line, t_map *map);

char	**map_in_array(char *name, t_map *map);
void	paste_img(t_map *map, t_mlx *mlx, char	*imgname);
void	map_draw(t_map *map, t_mlx *mlx);
void	player_pos(t_map *map);
void	init_mlx(t_mlx *mlx, t_map *map);

void player_img(t_mlx *mlx);
#endif