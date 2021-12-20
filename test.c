# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"

int main(void)
{
	char	**line;
	char	*linegnl;
	int		fd;
	int		i;
	int		j;
	int		len;
	int		len1;

	i = 0;
	fd = open("map.ber", O_RDONLY);
	linegnl = get_next_line(fd);
	len = ft_strlen(linegnl);
	line[i] = (char *)malloc(sizeof(char) * len + 1);
	line[i] = linegnl;
	i++;
	while (linegnl)
	{
		linegnl = get_next_line(fd);
	// 	// free(linegnl);
		line[i] = (char *)malloc(100);
		line[i] = linegnl;
		i++;
		
	}
	
	while (j < i - 1)
	{
		printf("%s", line[j]);
		j++;
		
	}
	// printf("\n%c", line[1][5]);

	while (1)
		;
	return (0);
}