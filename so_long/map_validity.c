/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:59:45 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/26 16:35:19 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

void	map_validity(t_map *map, int argc, char *mapf)
{
	if (argc == 2)
	{
		init_map(map);
		map->fd = open(mapf, O_RDONLY);
		if (map->fd < 0)
			exit_error(3);
		map->line = get_next_line(map->fd);
		map->len = ft_strlen(map->line);
		map->columns = map->len - 1;
		map_name(mapf);
		map_top(map->line, map);
		map_mid_end(map->line, map);
		map_pec_size(map);
		map->map_in_array = map_in_array(mapf, map);
	}
	else
		exit_error(10);		// не забыть очистить массив
}

void	map_name(char	*name)
{
	int	i;

	i = 0;
	while (name[i] != '.')
		i++;
	i++;
	if (name[i] != 'b' && name[i + 1] != 'e'
		&& name[i + 2] != 'r' && name[i + 3] != '\0')
		exit_error(6);
}

void	p_e_c_num(char	*line, t_map *map)
{
	while (map->line[map->j])
	{
		if (map->line[map->j] == 'E')
			map->ee++;
		if (map->line[map->j] == 'P')
			map->pp++;
		if (map->line[map->j] == 'C')
			map->cc++;
		map->j++;
	}
	map->j = 0;
}

void	map_pec_size(t_map	*map)
{
	if (map->ee < 1 || map->pp != 1 || map->cc < 1)
		exit_error(1);
	if (map->len - 1 == map->lines)
		exit_error(2);
}


