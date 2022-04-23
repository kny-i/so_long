#include "../include/so_long.h"

void	put_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILLLENO);
	return (0);
}