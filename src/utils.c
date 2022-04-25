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

char	*ft_stradd_back(char *str, char buff)
{
	int		i;
	char 	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (ret == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buff;
	i++;
	ret[i] = '\0';
	return (ret);

}

int 	get_next_line_count(int fd, char **str)
{
	char 	buff;
	int 	ret;

	ret = read(fd, &buff, 1);
	ret++;
	while(ret > 0)
	{
		*str = ft_stradd_back(*str, buff);
		if (buff == '\n')
			return (ret);
		ret = read(fd, &buff, 1);
		ret++;
	}
	return (ret);
}




