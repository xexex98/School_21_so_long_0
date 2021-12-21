# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"


char **map_in_array(void)
{
	char	**array;
	char	*linegnl;
	int		fd;
	int		i;

	i = 0;
	fd = open("map.ber", O_RDONLY);
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

int main(void)
{
	char	**array;

	array =	map_in_array();
	printf("%s\n", array[0]);
	// while (1)
		// ;
	return (0);
}
// free
	// for (int j = 0; j < i; j++)
	// {
	// 	printf("%s", array[j]);
	// 	free(array[j]);
	// }
	// free(array);

// int main(void)
// {
// 	char	**line;
// 	char	*linegnl;
// 	int		fd;
// 	int		i;

// 	i = 0;
// 	fd = open("map.ber", O_RDONLY);
// 	while ((linegnl = get_next_line(fd)))
// 	{
// 		line[i] = linegnl;
// 		i++;
// 	}
// 	for (int j = 0; j < i; j++)
// 		printf("%s", line[j]);
// 	close(fd);
// 	// while (1)
// 		// ;
// 	return (0);
// }
