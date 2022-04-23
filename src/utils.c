#include "../minilibx-linux/mlx.h"

void	put_error(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}