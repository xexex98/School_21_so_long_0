/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:23 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/16 21:23:47 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_map
{
	int		E;
	int		P;
	int		C;
	int		i;
	int		j;
	int		columns;
	int		len;
	int		lines;
	char	*line;
	int		fd;
}				t_map;

t_map	*init_map(t_map *map)
{
	map->E = 0;
	map->P = 0;
	map->C = 0;
	map->i = 0;
	map->j = 0;
	map->columns  = 0;
	map->len = 0;
	map->lines = 1;
	map->fd = 0;
	map->line = NULL;
	return (map);
}

void	map_pec_num(char	*line, t_map *map)
{
	while (map->line[map->j])
	{
			if (map->line[map->j] == 'E')
				map->E++;
			if (map->line[map->j] == 'P')
				map->P++;
			if (map->line[map->j] == 'C')
				map->C++;
			map->j++;
	}
	map->j = 0;
	return ;
}

int	map_top(char	*line, t_map *map)
{
	while (map->line[map->i] != '\n')
	{
		if (map->line[map->i] == '1')
			map->i++;
		else
			return (0);
	}
	map->i = 0;
	free(map->line);
	return (1);
}

int	map_mid_end(char *line, t_map *map)
{
	while ((map->line = get_next_line(map->fd)))
	{
		map->lines++;
		if (map->line[map->columns] == '\0')
		{
			while (line[map->i])
			{
				if (map->line[map->i] == '1')
					map->i++;
				else
					return (0);
			}
		}	
		else if (map->line[map->columns] == '\n')
		{
			map_pec_num(map->line, map);
			if (map->line[0] != '1' || map->line[map->columns - 1] != '1')
				return (0);
		}
		else
			return (0);
		free(map->line);
	}
	return (1);
}

int	map_pec_size(t_map	*map)
{
	if (map->E < 1 || map->P != 1 || map->C < 1)
		return (0);
	if (map->len - 1 == map->lines)
		return (0);
	return (1);
}

int	main(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (-1);
	init_map(map);
	map->fd = open("map.ber", O_RDONLY);
	map->line = get_next_line(map->fd);
	map->len = ft_strlen(map->line);
	map->columns = map->len - 1;
	if (map_top(map->line, map) == 1 && map_mid_end(map->line, map) == 1 && map_pec_size(map) == 1)
		printf("OK");
	else
		printf("NOK");
	return (0);
}