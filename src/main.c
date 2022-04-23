#include "../minilibx-linux/mlx.h"
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

int	main(int arg, char **argv)
{
	t_data	*data;

	if (argc != 2)
		put_error("invalid argument");
	data->count = 0;
	data->mlx_ptr = mlx_init();
	data_init(data->content);

}