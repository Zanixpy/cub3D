CC          = cc
CFLAGS      = -g3 -O2 -Wall -Wextra -Werror -Wno-error=incompatible-pointer-types

SRCS        = src/main.c \
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
              src/utils/texture_utils.c \
              src/utils/bool_utils.c \
              src/utils/ft_atoi.c \
              src/utils/ft_putendl_fd.c \
              src/utils/ft_split.c \
              src/utils/get_next_line.c \
              src/utils/ft_strdup.c \
              src/utils/ft_isdigit.c \
              src/utils/ft_strlen.c \
              src/utils/ft_isalpha.c \
              src/utils/ft_strncmp.c \
              src/utils/ft_bzero.c \
              src/utils/ft_calloc.c \
              src/utils/ft_tolower.c \
              src/utils/ft_toupper.c \
              src/utils/ft_strjoin.c \
              src/utils/ft_strchr.c \
              src/utils/ft_strtrim.c \
              src/raycasting/raycasting.c \
              src/raycasting/render.c \
              src/raycasting/moves.c \
              src/raycasting/hook.c

MLX_DIR     = external/mlx
MLX         = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

HEADERS     = include
INCLUDES    = -I$(HEADERS) -I$(MLX_DIR)

OBJS        = $(SRCS:.c=.o)

NAME        = cub3D

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean