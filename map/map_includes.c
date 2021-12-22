/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_includes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:12:30 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/22 18:19:26 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long/so_long.h"

char	**map_in_array(char *name)
{
	char	**array;
	char	*linegnl;
	int		fd;
	int		i;

	i = 0;
	fd = open(name, O_RDONLY);
	array = malloc(100);
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
			printf("Norm");
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
