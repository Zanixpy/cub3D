CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

SRCS =  src/main.c \
		src/parser/parser.c \
		src/parser/parser_utils.c \
		src/parser/load_map.c \
		src/parser/load_elements.c \
		src/parser/init_mlx.c \
		src/parser/errors.c \
		src/parser/check_game_config.c \
		src/struct/struct_handling.c \
		src/utils/memory_utils.c \
		src/utils/utils.c \
		src/utils/time_utils.c \
		src/raycasting/raycasting.c \
		src/raycasting/render.c \
		src/raycasting/moves.c \
		src/raycasting/hook.c \


		
LIBFT_DIR = external/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = external/mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAG= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
LIBFT_FLAG= -L $(LIBFT_DIR) -lft

HEADERS = include

OBJS    = $(SRCS:.c=.o)

INCLUDES = -I$(HEADERS) -I$(LIBFT_DIR)

NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAG) $(MLX_FLAG)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all re fclean clean