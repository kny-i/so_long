#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <libc.h>

typedef struct img_s
{
	int		height;
	int		width;
	void	*img_floor;
	void	*img_player;
	void	*img_wall;
	void	*img_collect;
	void	*img_exit;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}t_img;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}			t_cnt;

typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}			t_data;

void	put_error(char *message);
char	**read_map(char **str, t_data *data);
int		terminate_mlx(t_data *data);
void	data_init(t_cnt *content);
void	*ft_free_map(t_data *data);
void	ft_count_contents(t_data *data);
char	**parse_map(int fd, t_data *data);
char	**read_map(char **str, t_data *data);
char	*get_map_data(int fd);
void	ft_error(char *message);
int		ft_strnrcmp(char *str, char *cmp);
int		get_next_line_count(int fd, char **str);
void	init_render(t_data *data);
void	render_other(t_data *data);
void	render_background(t_data *data);
int		key_press(int key_data, t_data *data);
void	render_down(t_data *data);
void	render_left(t_data *data);
void	render_right(t_data *data);
void	render_up(t_data *data);
int		ft_check_format(t_data *data);
int		ft_check_line(t_data *data);
int		ft_check_col(t_data *data);
int		ft_check_other(t_data *data);

#endif