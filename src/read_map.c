#include "../include/so_long.h"

char *get_map_data(int fd)
{
	char 	*line_map;
	char 	*buff;
	char 	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	line_map = get_next_line(fd);
	if (ft_strlen(line_map) != 0)
	{
		tmp_buff = buff;
		while(ft_strlen(line_map) != 0)
		{
			buff = ft_strjoin(buff, line_map);
			free(tmp_buff);
			free(line_map);
			line_map = ft_strdup("");
			line_map = get_next_line(fd);
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
	return(0);
}

void	ft_count_contents(t_data data)
{

}

char	**parse_map(int fd, t_data *data)
{
	int 	i;

	i = 1;
	data->map = ft_split(get_map_data(fd), '\n');
	ft_count_contents(data);
	return (data->map);
}

char **read_map(char **str, t_data *data)
{
	int 	fd;

	fd = 0;
	data->map = NULL;
	if (ft_strchr([1], ".ber") == 0)
	{
		ft_error("invalid file_name");
		return (NULL);
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = parse_map(fd, data);
		else
		{
			ft_error("something wrong with fd");
			return(NULL);
		}
		if ((data->content.count_p != 1 || data->content->count_c == 0 \
					|| data->content->count_e != 1 ))
		{
			ft_free_map(data);
			ft_error("not enough player, object or exit");
			return (NULL);
		}
	}
	return (data->map);
}