/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:41 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/26 18:13:00 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

t_map	*init_map(t_map *map)
{
	map->ee = 0;
	map->pp = 0;
	map->cc = 0;
	map->i = 0;
	map->j = 0;
	map->columns = 0;
	map->len = 0;
	map->lines = 1;
	map->line = NULL;
	map->fd = 0;
	map->map_in_array = NULL;
	return (map);
}

void	map_top(char	*line, t_map *map)
{
	map->i = 0;
	while (map->line[map->i] != '\n')
	{
		if (map->line[map->i] != '1')
			exit_error(4);			
		map->i++;
	}
	free(map->line);
}

void	map_mid(t_map *map)
{
	map->i = 0;
	p_e_c_num(map->line, map);
	if (map->line[0] != '1' || map->line[map->columns - 1] != '1')
		exit_error(4);
	while (map->line[map->i])
	{
		if (map->line[map->i] != '1' && map->line[map->i] != '0'
			&& map->line[map->i] != 'P' && map->line[map->i] != 'E'
			&& map->line[map->i] != 'C' && map->line[map->i] != '\n')
			exit_error(5);
		map->i++;
	}
	map->i = 0;
}

void	map_end(t_map *map)
{
	map->i = 0;
	while (map->line[map->i])
	{
		if (map->line[map->i] == '1')
			map->i++;
		else
			exit_error(4);
	}
	map->i = 0;
}

void	map_mid_end(char *line, t_map *map)
{
	map->line = get_next_line(map->fd);
	free(map->line);
	while ((map->line != NULL))
	{
		map->lines++;
		if (map->line[map->columns] == '\0')
			map_end(map);
		else if (map->line[map->columns] == '\n')
			map_mid(map);
		else
			exit_error(6);
		map->line = get_next_line(map->fd);
		free(map->line);
	}
}
