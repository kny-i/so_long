CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	so_long

SRCS_PATH		= 	./src/
MLX_PATH		= 	./minilibx-linux/
LIBFT_PATH		= 	./libft/
GNL_PATH		=   ./get_next_line/

SRCS_FILES		= 	main.c read_map.c utils.c render.c init.c
GNL_FILES		= 	get_next_line.c get_next_line_utils.c

SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_OBJS		= 	$(SRCS:.c=.o)
GNL				= 	$(addprefix $(GNL_PATH), $(GNL_FILES))
GNL_OBJS		= 	$(GNL:.c=.o)
MLXMAKE			= 	$(MAKE) -C $(MLX_PATH)
MLXFLAG			= 	-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)

all:			$(NAME)


$(NAME):		$(MLX_PATH) $(SRCS_OBJS) $(GNL_OBJS)
				$(MLXMAKE)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(GNL_OBJS) $(MLXFLAG) $(MLX_PATH)/libmlx_Darwin.a $(LIBFT_PATH)/libft.a -o $(NAME)

mlx:
				$(MLXMAKE)



clean:
				$(MLXMAKE) clean
				$(LIBFTMAKE) clean
				$(RM) $(SRCS_OBJS)
				$(RM) $(GNL_OBJS)

fclean:			clean
				$(RM) $(MLX_PATH)/libmlx_Darwin.a
				$(LIBFTMAKE) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean mlx re