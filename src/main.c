#include "../include/so_long.h"
void	data_init(t_cnt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

void	terminate(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		mlx_destroy_image(data->mlx_ptr, data->img.img_win);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	main(int arg, char **argv)
{
	t_data	*data;

	if (argc != 2)
		put_error("invalid argument");
	data->count = 0;
	data->mlx_ptr = mlx_init();
	data_init(data->content);
	data->map = read_map(argv, &data);
	if (data->map == NULL)
		terminate_mlx(data);
	else
	{
		set_img(data);
		render_map(data);
	}
	return (0);
}
