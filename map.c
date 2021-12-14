/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:23 by mbarra            #+#    #+#             */
/*   Updated: 2021/12/14 18:06:45 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		gnl;
	int		len;
	char	*line;
	int		i;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line[i] != '\n')
	{
		if (line[i] == '1')
			i++;
		else
			return (printf("Error\n"));
	}
	i = 0;
	// printf ("%i", i);
	printf("\n%s", line);
	while ((line = get_next_line(fd)))
	{
			
			if (line[len - 1] == '\0')
			{
				while (line[i] != '\0')
				{
					if (line[i] == '1')
						i++;
					else
						return (printf("Error\n"));
				}
			}		
			if (line[0] == '1' && line[len - 2] == '1')
				printf("OK");
			else
				return (printf("Error\n"));

		printf("\n%s", line);
		// free(line);
	}
	// line = get_next_line(fd);
	// printf("\n%s", line);

	// while (line[i] != '\n')
	// {
	// 	if (line[i] == '1')
	// 		i++;
	// 	else
	// 		return (printf("Error\n"));
	// }
	// printf("%i", gnl);
	// if (gnl == 0);
	// {
	// 	while (line[i++] != '\n')
	// 		len++;
	// }
	// printf("%s", line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// len++;
	// len = ft_strlen(line);
	// printf("%i", len);
	// if (gnl == 0)
	// {
		// if ()
		// printf("OK");
	// }
	// else
		// printf("NOK");/
	// free(line);
	// printf("\n%s", line);
	// while ((bytes = read(fd, &ch, 1)) > 0)
	// {
	// 	if (ch == '1')
	// 		len++;
	// 	if (ch == '\n')
	// 		n++;
	// 	printf("%c", ch);
	// }
	// printf("\nlen:%i", len);
	// printf("\nn:%i", n);
	return (0);
}