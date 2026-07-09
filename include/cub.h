/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:21:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/09 12:33:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

/* ===================================
 EXTERNAL LIB
=================================== */

# include "../external/libft/libft.h"
# include "../external/mlx/mlx.h"

/* ===================================
 SYSTEM LIB
=================================== */

# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

/* ===================================
 MACRO
=================================== */

# define SPACE ' '
# define WALL 1
# define EMPSPACE 0
# define PLAYER_DIR 'N' || 'S' || 'E' || 'W'
# define ERRMALLOC 15
# define SCREENWIDTH 640
# define SCREENHEIGHT 480

/* ===================================
 STRUCT
=================================== */

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;

	char	*filename;
	int		fd;

	void	*mlx;
	void	*mlx_win;

	char	player_direction;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planX;
	double	planY;
	double  cameraX;
	double  cameraY;
	double  rayDirX;
	double  rayDirY;
	double  sideDistX;
	double  sideDisty;
	int foward;
	int left;
	int right;
	int backwards;

	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	void	*texture[4];

	int		floor_RGB[3];
	int		ceiling_RGB[3];

}			t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

// struct_handling.c
t_game		*struct_init(void);
void		struct_destroy(t_game **game);

/* ===================================
 MLX WINDOW
=================================== */

// set_textures.c
int			set_floor_ceiling(t_game *game);
int set_2D_grid(t_game *game);
int	create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// set_moves.c
int handleKeyPress(int keycode, void *param);
int handleKeyRelease(int keycode, void *param);
int handleMoves(void *param);

/* ===================================
 PARSER
=================================== */

// parser_errors.c
void		exit_err_parser(int code);
void		err_parser(int code);
void		exit_parser_free_struct(t_game **game, int code);
void		err_mlx(int code);
void		exit_mlx_free_struct(t_game **game, int code);

// parser_get_element.c
int			fill_data(t_game *game);

// parser_get_map.c
int			fill_map(t_game *game);
int			is_map_element(t_game *game, char *line);

// parser_mlx.c
int			init_mlx(t_game *game);

// parser_utils.c
int			is_element(char *line);
int			is_RGB(char *str);
int			is_element_complete(t_game *game);
int			get_fd_and_filename(t_game *game, char *av);

// parser.c
int			parser(char **av, t_game **game);

/* ===================================
 UTILS
=================================== */

// utils.c
int			ft_strcmp(const char *s1, const char *s2);
int			array_size(char **tab);
char		*clean_str(char *s, int mode);

// memory_utils.c
void		free_char_array_n(char ***tab, int n);
void		free_char_array(char ***tab);
void		free_str(char **s);
void		close_fd(int *fd);
char		**ft_arrdup(char **tab);

// main.c
void		print_map(char **map);

#endif