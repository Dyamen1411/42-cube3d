SRC_DIR	=	srcs
INC_DIR	=	includes
MLX_DIR	=	minilibx-linux

FILES	=	c3d_game_loop.c	\
			c3d_key_hook.c	\
			c3d_mlx.c	\
			ctx_c3d.c	\
			main.c		\

SRCS	=	$(addprefix $(SRC_DIR)/,$(FILES))
OBJS	=	$(SRCS:%.c=%.o)


CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I$(MLX_DIR)	\
			-g
LFLAGS	=	-L$(MLX_DIR) -lmlx -lm -lX11 -lXext

TARGET	=	cube3d

.PHONY: all clean fclean re

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< -I$(INC_DIR) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all