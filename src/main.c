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

int	terminate_mlx(t_data *data)
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
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	}
	exit(0);
}

void	set_img(t_data *data)
{
	data->img.height = 30;
	data->img.width = 30;
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, \
			   data->img.wall, &(data->img.width), &(data->img.height));
	if (data->img.img_wall == NULL)
		put_error("Error\ncan not input img correctly\n");
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, \
				data->img.floor, &(data->img.width), &(data->img.height));
	if (data->img.img_floor == NULL)
		put_error("Error\ncan not input img correctly\n");
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, \
			   data->img.exit, &(data->img.width), &(data->img.height));
	if (data->img.img_exit == NULL)
		put_error("Error\ncan not input img correctly\n");
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr, \
			  data->img.collect, &(data->img.width), &(data->img.height));
	if (data->img.img_collect == NULL)
		put_error("Error\ncan not input img correctly\n");
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr, \
			 data->img.player, &(data->img.width), &(data->img.height));
	if (data->img.img_player == NULL)
		put_error("Error\ncan not input img correctly\n");
}

void	set_img_path(t_data *data)
{
	data->img.floor = "./rsrc/floor_texture.xpm";
	data->img.wall = "./rsrc/wall_texture.xpm";
	data->img.collect = "./rsrc/collect.xpm";
	data->img.player = "./rsrc/mario_player.xpm";
	data->img.exit = "./rsrc/exit_texture.xpm";
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		put_error("Error\ninvalid argument");
	data.count = 0;
	data.mlx_ptr = mlx_init();
	data_init(&data.content);
	data.map = read_map(argv, &data);
	if (data.map == NULL)
		terminate_mlx(&data);
	else
	{
		set_img_path(&data);
		set_img(&data);
		init_render(&data);
	}
	return (0);
}
