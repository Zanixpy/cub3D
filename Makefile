CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  src/main.c \
		src/parser/parser_errors.c \
		src/parser/parser_get_element.c \
		src/parser/parser_get_map.c \
		src/parser/parser_utils.c \
		src/parser/parser.c \
		src/struct/struct_handling.c \
		src/utils/memory_utils.c \
		src/utils/utils.c \


		
LIBFT_DIR = external/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = external/mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAG= -L$(MLX_DIR)  -lmlx -framework OpenGL -framework AppKit
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
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all re fclean clean