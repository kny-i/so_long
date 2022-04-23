#include "../minilibx-linux/mlx.h"

int	main(int arg, char **argv)
{
	t_data	*data;

	if (argc != 2)
		put_error("invalid argument");
	data->count = 0;
	data->mlx_ptr = mlx_init();
	data_init();

}