#include "../include/so_long.h"

void	put_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	return ;
}


int		ft_strnrcmp(char *str, char *cmp)
{
	int 	i;
	int 	k;

	i = ft_strlen(str);
	k = ft_strlen(cmp);
	if (str == NULL || cmp == NULL)
		return (0);
	if (i >= k)
	{
		while (k > 0)
		{
			if (str[i] != cmp[k]) 
			{
				return (0);
			}
			i--;
			k--;
		}
		return (1);
	}
	else
		return (0);

}
