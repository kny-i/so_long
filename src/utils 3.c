#include "../include/so_long.h"

void	put_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

int	ft_strrcmp(char *str, char *cmp)
{
	int	i;
	int	k;

	i = ft_strlen(str);
	k = ft_strlen(cmp);
	if (str == NULL || cmp == NULL)
		return (0);
	if (i >= k)
	{
		while (k > 0)
		{
			if (str[i] != cmp[k])
				return (0);
			i--;
			k--;
		}
		if (ft_strlen(str) == ft_strlen(cmp) + MAP_PATH_LEN)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

void	*ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	return (NULL);
}

int	key_press(int key_data, t_data *data)
{
	if (key_data == KEY_ESC)
		terminate_mlx(data);
	if (key_data == 'w')
		render_up(data);
	if (key_data == 'd')
		render_right(data);
	if (key_data == 'a')
		render_left(data);
	if (key_data == 's')
		render_down(data);
	return (0);
}
