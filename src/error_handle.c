#include "../include/so_long.h"

int 	ft_check_format(t_data *data)
{
	int 	y;
	int 	x;
	int 	count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (data->map[0][count_x])
		count_x++;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
			x++;
		if (x != count_x)
		{
			ft_error("Map must be a rectangle or a square\n");
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int	ft_check_col(t_data *data)
{
	int 	x;
	int		y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
		{
			if (y != 0 || y != data->height)
			{
				if (data->map[y][0] != data->content.wall || data->map[y][x - 1] != data->content.wall) {
					ft_error("Error\nMap column not close\n");
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	return (1);
}

int 	ft_check_other(t_data *data)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
		{
			if (data->content.count_e > 1 || data->content.count_p > 1)
			{
				ft_error("Error\nWrong number of player or exit\n");
				return (0);
			}
			if (data->map[y][x] != data->content.wall && data->map[y][x] != data->content.player
				&& data->map[y][x] != data->content.exit && data->map[y][x] != data->content.collect
				&& data->map[y][x] != data->content.space)
			{
				ft_error("Error\nUnknown symbol(s) in map\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int ft_check_line(t_data *data)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] != data->content.wall)
		{
			ft_error("Map line doesn't close");
			return (0);
		}
		x++;
	}
	y = data->height;
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] != data->content.wall)
		{
			ft_error("Map line doesn't close");
			return (0);
		}
		x++;
	}
	return (1);
}

