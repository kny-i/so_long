#include "../include/so_long.h"

int	chk_collect(t_data *data)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->content.collect)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

void	render_up(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y - 1][pos_x] != data->content.exit)
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				data->count++;
				ft_printf("count: %d\ncongrats!!\n", data->count);
				terminate_mlx(data);
			}
		}
	}
}

void	render_right(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x + 1] != data->content.exit)
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				data->count++;
				ft_printf("count: %d\ncongrats!!\n", data->count);
				terminate_mlx(data);
			}
		}
	}
}

void	render_left(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x - 1] != data->content.exit)
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				data->count++;
				ft_printf("count: %d\ncongrats!!\n", data->count);
				terminate_mlx(data);
			}
		}
	}
}

void	render_down(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x;
	pos_y = data->pos.y;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y + 1][pos_x] != data->content.exit)
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			ft_printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				data->count++;
				ft_printf("count: %d\ncongrats!!\n", ++data->count);
				terminate_mlx(data);
			}
		}
	}
}
