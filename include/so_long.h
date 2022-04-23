#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"

# include "./get_next_line/get_next_line.h"
# include <libc.h>

typedef struct img_s
{
	int		height;
	int 	width;
	void	*img_floor;
	void	*img_player;
	void	*img_wall;
	void	*img_correct;
	void	*img_exit;
	char	*player;
	char	*foor;
	char	*wall;
	char	*collect;
	char 	*exit;
}t_info;

typedef struct cnt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char 	space;
	int		count_p;
	int 	count_e;
	int 	count_c;
}			t_cnt;

typedef	struct pos_s
{
	int 	x;
	int 	y;m
}				t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mls_win;
	int 	width;
	int		height;
	char	**map;
	t_cnt	content;
	t_img	img;
	t_pos	pos;
	int 	count;
} t_data;