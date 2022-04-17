#include "../get_next_line/get_next_line.h"
int	main ()
{
	char	**line;
	int		fd;
	int		i;
	int		x_size;

	i = 0;
	fd = open("../test/test.txt", O_RDONLY);
	line = (char **)malloc(100*sizeof(char **));
	printf("%d\n",fd);
	while (i < 4)
	{
		line[i] = (char *)malloc(100 * sizeof(char *));
		line[i] = get_next_line(fd);
		x_size = ft_strlen(line[i]);
		if (!line[i])
		{
			printf("\nEOF or ERROR\n");
			break ;
		}
		printf("line[%d]: %s\n", i , line[i]);
		printf("[%d行目]%d文字\n", i, x_size );
		free(line[i]);
		i++;
	}
	free(line);
	close(fd);
}