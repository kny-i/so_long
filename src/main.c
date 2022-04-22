#include "../minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}