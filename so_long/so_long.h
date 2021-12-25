/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:26:18 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/25 18:22:17 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define PIXELS	40
# define A		0
# define S		1
# define D		2
# define W		13
# define ESC	53

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

// typedef struct s_mlx
// {
// 	void	*mlx;
// 	void	*win;
// }				t_mlx;

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		endian;
}				t_img;


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

# define WIN_HEIGHT	800
# define WIN_WIDTH	600

void	ft_putstr(char	*str);

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(char *buf2, int fd);
char	*ft_line(char *buf2);
char	*ft_line_reminder(char *buf2);
int		ft_strlen_n(char *s);

t_map	*init_map(t_map *map);
void	map_pec_num(char	*line, t_map *map);
int		map_pec_size(t_map	*map);
int		map_checker(char *mapf, t_map *map);
int		free_map(t_map *map, char *mapf);
int		map_top(char	*line, t_map *map);
int		map_mid(t_map *map);
int		map_end(t_map *map);
int		map_mid_end(char *line, t_map *map);
int		map_name(char	*name);

// char	**map_in_array(char	*name);
char	**map_in_array(char *name, t_map *map);
int		map_check_fin(t_map *map, int argc, char *argv);
void	paste_img(t_map *map, t_img *img, t_mlx *mlx, char	*imgname);
void	map_draw(t_map *map, t_img *img, t_mlx *mlx);

#endif