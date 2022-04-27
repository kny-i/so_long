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

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y - 1][pos_x] != data->content.exit)
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					   data->count);
				terminate_mlx(data);
			}
		}
	}
}

void	render_right(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x + 1] != data->content.exit)
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					   data->count);
				terminate_mlx(data);
			}
		}
	}
}

void	render_left(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (data->map[pos_y][pos_x - 1] != data->content.exit)
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					   data->count);
				terminate_mlx(data);
			}
		}
	}
}

void	render_down(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (data->map[pos_y + 1][pos_x] != data->content.exit)
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("Felicitation vous avez gagne en : %d coup !\n",
					   data->count);
				terminate_mlx(data);
			}
		}
	}
}





int	key_press(int key_data, t_data *data)
{
	if (key_data == XK_EScape)
		terminate_mlx(data);
	if (key_data == XK_w)
		render_up(data);
	if (key_data == XK_d)
		render_right(data);
	if (key_data == XK_a)
		render_left(data);
	if (key_data == XK_s)
		render_down(data);
	return (0);
}