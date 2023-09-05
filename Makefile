TARGET	=	cube3d

MLX_DIR	=	minilibx-linux
MLX		=	$(MLX_DIR)/libmlx.a

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -I$(MLX_DIR)	\
			-g
LFLAGS	=	-L$(MLX_DIR) -lmlx -lm -lX11 -lXext

SRC_DIR	=	srcs
INC_DIR	=	includes

FILES	=	\
			c3d/ctx.c					\
			c3d/game_loop.c				\
			c3d/hook__key.c				\
			c3d/hook__resize.c			\
			c3d/key_bindings.c			\
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

.PHONY: all clean fclean re run debug

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

run: $(TARGET)
	./gen_map.sh | ./$(TARGET)

debug: $(TARGET)
	./gen_map.sh | valgrind ./$(TARGET)

$(MLX):
	git submodule init $(MLX_DIR)
	git submodule update $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(TARGET): $(MLX) $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< -I$(INC_DIR) $(CFLAGS)
