/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:50:24 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/22 17:31:27 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

int	map_top(char	*line, t_map *map)
{
	while (map->line[map->i] != '\n')
	{
		if (map->line[map->i] == '1')
			map->i++;
		else
		{
			ft_putstr("Wall error!");
			return (0);
		}
	}
	map->i = 0;
	free(map->line);
	return (1);
}

int	map_mid(t_map *map)
{
	map->i = 0;
	map_pec_num(map->line, map);
	if (map->line[0] != '1' || map->line[map->columns - 1] != '1')
	{
		ft_putstr("Wall error!");
		return (0);
	}
	while (map->line[map->i])
	{
		if (map->line[map->i] != '1' && map->line[map->i] != '0'
			&& map->line[map->i] != 'P' && map->line[map->i] != 'E'
			&& map->line[map->i] != 'C' && map->line[map->i] != '\n')
		{
			ft_putstr("Undefined symbol!");
			return (0);
		}
		map->i++;
	}
	map->i = 0;
	return (1);
}

int	map_end(t_map *map)
{
	map->i = 0;
	while (map->line[map->i])
	{
		if (map->line[map->i] == '1')
			map->i++;
		else
		{
			ft_putstr("Wall error!");
			return (0);
		}
	}
	map->i = 0;
	return (1);
}

int	map_mid_end(char *line, t_map *map)
{
	map->line = get_next_line(map->fd);
	free(map->line);
	while ((map->line != NULL))
	{
		map->lines++;
		if (map->line[map->columns] == '\0')
		{
			if (map_end(map) == 0)
				return (0);
		}	
		else if (map->line[map->columns] == '\n')
		{
			if (map_mid(map) == 0)
				return (0);
		}
		else
		{
			ft_putstr("Non-rectangular map!");
			return (0);
		}
		map->line = get_next_line(map->fd);
		free(map->line);
	}
	return (1);
}

int	map_name(char	*name)
{
	int	i;

	i = 0;

	while (name[i] != '.')
		i++;
	i++;
	if (name[i] == 'b' && name[i + 1] == 'e'
		&& name[i + 2] == 'r' && name[i + 3] == '\0')
		return (1);
	else
	{
		ft_putstr("Wrong map extension!");
		return (0);
	}
}
