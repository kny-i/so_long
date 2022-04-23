CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	so_long

SRCS_PATH		= 	./src/
MLX_PATH		= 	./minilibx-linux/

SRCS_FILES		= 	*.c

SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_OBJS		= 	$(SRCS:.c=.o)

MLXMAKE			= 	$(MAKE) -C $(MLX_PATH)
MLXFLAG			= 	-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

all:			$(NAME)


$(NAME):		$(MLX_PATH) $(SRCS_OBJS)
				$(MLXMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS)  $(MLXFLAG) $(MLX_PATH)/libmlx_Darwin.a -o $(NAME)

mlx:
				$(MLXMAKE)

.c.o:
				$(CC) $(CFLAGS) -I -c $< -o $@

clean:
				$(MLXMAKE) clean
				$(RM) $(SRCS_OBJS)

fclean:			clean
				$(RM) $(MLX_PATH)/libmlx.dylib
				$(RM) $(NAME) $(SRCS_OBJS)

re:				fclean all

.PHONY:			all clean fclean mlx re