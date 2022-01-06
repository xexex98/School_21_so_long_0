/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:26:18 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/06 17:43:29 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define PIXELS	40
# define A		0
# define S		1
# define D		2
# define W		13
# define ESC	53

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	void	*img8;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		endian;
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
	int		x;
	int		y;
	int		coins;
	int		all_coins;
	int		moves;
	int		eo;
	int		time;
	int		frame;
}				t_mlx;

void	exit_error(int error);
int		close_game(t_mlx *mlx);
void	free_map(t_mlx *mlx);

void	coin(t_mlx	*mlx);
void	gexit(t_mlx *mlx);
void	death(t_mlx *mlx);
void	move(t_mlx *mlx, int x, int y);
int		key_press_hook(int keycode, t_mlx *mlx);

size_t	ft_intlen(int c);
char	*ft_itoa(int n);
void	init_mlx(t_mlx *mlx);

char	**map_in_array(char *name, t_mlx *mlx);
void	map_draw_2(t_mlx *mlx);
void	map_draw_3(t_mlx *mlx);
void	map_draw(t_mlx *mlx);
void	player_pos(t_mlx *mlx);

void	init_map(t_mlx *mlx);
void	map_top(char	*line, t_mlx *mlx);
void	map_mid(t_mlx *mlx);
void	map_end(t_mlx *mlx);
void	map_mid_end(char *line, t_mlx *mlx);

void	map_validity(t_mlx *mlx, int argc, char *mapf);
void	map_name(char	*name);
void	p_e_c_num(char	*line, t_mlx *mlx);
void	map_pec_size(t_mlx *mlx);
void	open_img(t_mlx *mlx);

void	animathion(t_mlx *mlx);
int		paste_img_2(t_mlx *mlx);
void	norm1(t_mlx *mlx, int i, int j);
void	norm2(t_mlx *mlx, int i, int j);

#endif