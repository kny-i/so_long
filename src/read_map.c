#include "../include/so_long.h"

char *get_map_data(int fd)
{
	char 	*line_map;
	char 	*buff;
	char 	*tmp_buff;
	int		count_line;

	line_map = get_next_line(fd);
	count_line = ft_strlen(line_map);
	buff = strdup("");
	tmp_buff = buff;
	if (count_line > 0)
	{
		while(count_line > 0)
		{
			buff = ft_strjoin(tmp_buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = get_next_line(fd);
			count_line = ft_strlen(line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	ft_error("internal map error");
	return(NULL);
}

void	ft_free_map(t_data *data)
{
	int 	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return ;
}

void	ft_count_contents(t_data *data)
{
	int 	i;
	int 	k;

	i = 0;
	k = 0;
	while (data->map[i])
	{
		while (data->map[i][k])
		{
			if (data->map[i][k] == data->content.collect)
				data->content.count_c += 1;
			if (data->map[i][k] == data->content.player)
				data->content.count_p += 1;
			if (data->map[i][k] == data->content.exit)
				data->content.count_e += 1;
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_count_line(t_data *data)
{
	int 	y;
	int 	x;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
			x++;
		y++;
	}
	data->width = x;
	data->height = y;
}

char	**parse_map(int fd, t_data *data)
{
	data->map = ft_split(get_map_data(fd), '\n');
	ft_count_contents(data);
	/*if (!(ft_check_line(data->map[0], data->content.wall)))
		return (ft_free_map(data));*/
	ft_count_line(data);
	return (data->map);
}

char **read_map(char **argv, t_data *data)
{
	int 	fd;

	data->map = NULL;
	if (ft_strnrcmp(argv[1], ".ber") == 0)
	{
		ft_error("invalid file_name");
		return (NULL);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			data->map = parse_map(fd, data);
		}
		else
		{
			ft_error("something wrong with fd");
			return(NULL);
		}
		if ((data->content.count_p != 1 || data->content.count_c == 0 \
					|| data->content.count_e != 1 ))
		{
			ft_free_map(data);
			ft_error("not enough player, object or exit");
			return (NULL);
		}
	}
	return (data->map);
}
