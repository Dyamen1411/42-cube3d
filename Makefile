TARGET		=	cube3d

MLX_DIR		=	minilibx-linux
MLX			=	mlx

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I$(MLX_DIR)	\
			-g -O4
LFLAGS		=	-L$(MLX_DIR) -l$(MLX) -lm -lX11 -lXext

SRC_DIR		=	srcs
INC_DIR		=	includes

FILES		=	\
				c3d/ctx.c					\
				c3d/game_loop.c				\
				c3d/hook__key.c				\
				c3d/key_bindings.c			\
				key_map/actions.c			\
				key_map/init.c				\
				key_map/key_map.c			\
				key_map/utils.c				\
				math/field2d.c				\
				math/vector2d.c				\
				mlx/ctx.c					\
				player/direction_key_map.c	\
				player/init.c				\
				player/movement_key_map.c	\
				player/player.c				\
				player/utils.c				\
				renderer/update_window.c	\
				renderer/world_renderer.c	\
				utils/io.c					\
				utils/utils.c				\
				world/field.c				\
				world/world_loader.c		\
				world/world.c				\
				main.c						\
				utils.c						\

SRCS		=	$(addprefix $(SRC_DIR)/,$(FILES))
OBJS		=	$(SRCS:%.c=%.o)
DEPS		=	$(SRCS:%.c=%.d)

NODEPS		=	clean fclean norminette

SUFFIXES	+=	.d

all: $(TARGET)

clean:
	rm -f $(DEPS)
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

run: $(TARGET)
	./gen_map.sh | ./$(TARGET)

debug: $(TARGET)
	./gen_map.sh | valgrind ./$(TARGET)

norminette:
	norminette $(SRC_DIR) $(INC_DIR)

$(MLX_DIR)/lib$(MLX).a:
	git submodule init $(MLX_DIR)
	git submodule update $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)


$(TARGET): $(MLX_DIR)/lib$(MLX).a $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

%.o: %.c %.d
	$(CC) -c -o $@ $< -I$(INC_DIR) $(CFLAGS)

%.d: %.c
	$(CC) -MM -MT '$(patsubst %.c,%.o,$<)' $< -MF $@ -I$(INC_DIR) $(CFLAGS)

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
-include $(DEPS)
endif

.PHONY: all clean fclean re run debug norminette
