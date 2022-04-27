#include "../include/so_long.h"

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
							data->img.width * x, data->img.height * y);
}

void	render_background(t_data *data)
{
	int 	i;
	int 	y;

	i = 0;
	y = 0;
	
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			if (data->map[y][i] == data->content.wall) 
			{
				print_img(data, data->img.img_wall, i, y);
			}
			if (data->map[y][i] == data->content.space)
			{
				print_img(data, data->img.img_floor, i, y);
			}
			i++;
		}
		i = 0;
		y++;
	}
}

void	render_other(t_data *data)
{
	int 	i;
	int 	y;

	i = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][i] != '\0')
		{
			printf("[%c]\n", data->map[y][i]);
			printf("i = [%d]\n", i);
			printf("y = [%d]\n", y);
			if (data->map[y][i] == data->content.collect)
			{
				printf("[%c]\n", data->content.collect);
				printf("k = [%d]\n", y);
				print_img(data, data->img.img_collect, i, y);
				printf("__test__100\n");
			}
			else if (data->map[y][i] == data->content.player)
			{
				printf("__test__99\n");
				data->pos.x = i * data->img.width;
				data->pos.y = y * data->img.height;
				print_img(data, data->img.img_player, i, y);
			}
			else if (data->map[y][i] == data->content.exit)
			{
				printf("__test__300\n");
				print_img(data, data->img.img_exit, i, y);

			}
			i++;
		}
		i = 0;
		y++;
	}
}

int	render_map(t_data *data)
{
	render_background(data);
	render_other(data);
	return (0);
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

void	init_render(t_data *data)
{
	printf("[%d]\n", data->width);
	printf("[%d]\n", data->img.width);
	printf("size_x = [%d]\n", data->width * data->img.width);
	printf("size_y = [%d]\n", (data->height * data->img.height));
	data->mlx_win = mlx_new_window(data->mlx_ptr, (data->width * data->img.width), \
											(data->height * data->img.height), "so_long");
	if	(data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render_map, data);
	mlx_hook(data->mlx_win, 03, 1L<<1, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &terminate_mlx, data);
	mlx_loop(data->mlx_ptr);
	terminate_mlx(data);
}