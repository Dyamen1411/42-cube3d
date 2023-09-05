SRC_DIR	=	srcs
INC_DIR	=	includes
MLX_DIR	=	minilibx-linux

FILES	=	\
			c3d/ctx.c					\
			c3d/game_loop.c				\
			c3d/key_bindings.c			\
			c3d/key_hook.c				\
			key_map/actions.c			\
			key_map/init.c				\
			key_map/key_map.c			\
			key_map/utils.c				\
			mlx/ctx.c					\
			player/direction_key_map.c	\
			player/init.c				\
			player/movement_key_map.c	\
			player/player.c				\
			player/utils.c				\
			utils/io.c					\
			world/world_loader.c		\
			world/world.c				\
			main.c						\
			utils.c						\

SRCS	=	$(addprefix $(SRC_DIR)/,$(FILES))
OBJS	=	$(SRCS:%.c=%.o)

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I$(MLX_DIR)	\
			-g
LFLAGS	=	-L$(MLX_DIR) -lmlx -lm -lX11 -lXext

TARGET	=	cube3d

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< -I$(INC_DIR) $(CFLAGS)

.PHONY: all clean fclean re

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all