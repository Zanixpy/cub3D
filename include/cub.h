/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:21:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/21 05:46:33 by omawele          ###   ########.fr       */
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
# define SCREENWIDTH 1920
# define SCREENHEIGHT 1080
# define TEXWIDTH 64
# define TEXHEIGHT 64

/* ===================================
 STRUCT
=================================== */

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;


typedef struct s_texture
{
	t_data 	display;
	t_data	NO_texture;
	t_data	SO_texture;
	t_data	WE_texture;
	t_data	EA_texture;

	int 	floor;
	int 	ceiling;
	
}	t_texture;


typedef struct s_player
{
	double move_speed;
	double rot_speed;
	int foward;
	int left;
	int right;
	int backward;
	int rotate_right;
	int rotate_left;
}	t_player;

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;

	char	*filename;

	void	*mlx;
	void	*mlx_win;

	char	player_direction;
	int 	map_x;
	int 	map_y;
	int		hit;
	int 	step_x;
	int 	step_y;
	int 	side;
	int draw_start;
	int draw_end;
	int line_height;
	int tex_x;
	int tex_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double old_dir_x;
    double old_plane_x;
	double	plane_x;
	double	plane_y;
	double  camera_x;
	double  camera_y;
	double  ray_dir_x;
	double  ray_dir_y;
	double  side_dist_x;
	double  side_dist_y;
	double  delta_dist_x;
	double  delta_dist_y;
	double  perp_wall_dist;
	double wall_x;
	double step;
	double tex_pos;
	double 	frame_time_ms;
	double 	last_frame;
	double  delta_time;
	t_player  p;
	t_texture tex;
}			t_game;



// struct_handling.c
t_game		*struct_init(void);
void		struct_destroy(t_game **game);

/* ===================================
 RAYCASTING
=================================== */

// raycasting.c
void raycasting(t_game *game);

// render.c
void draw_vertical_line(t_game *game, int x);
int render_graphics(void *param);

// moves.c
void    go_foward(t_game *game);
void    go_backward(t_game *game);
void    go_right(t_game *game);
void    go_left(t_game *game);
void    rotate_left(t_game *game);

// hook.c
int key_release(int code, void *param);
int key_hold(int code, void *param);
void    rotate_right(t_game *game);


/* ===================================
 PARSER
=================================== */

// check_game_config.c.c
int	check_player(t_game *game);
void	flood_algorithm(char ***map, int x, int y, t_game *game);
int	check_wall(t_game *game, char **map);

// errors.c
void		err_parser(int code);
void		err_mlx(int code);

// loads_elements.c
int	load_elements(t_game *game, int fd);

// load_map.c
int	load_map(t_game *game);
int			is_map_element(t_game *game, char *line);

// init_mlx.c
int			init_mlx(t_game *game);

// parser_utils.c
int			is_element(char *line);
int			is_RGB(char *str);
int	is_element_complete(t_texture *tex);
int check_filename(char *filename, char *extension);

// parser.c
int			parser(char **av, t_game **game);

/* ===================================
 UTILS
=================================== */

// utils.c
int			ft_strcmp(const char *s1, const char *s2);
int			array_size(char **tab);
char		*clean_str(char *s, int mode);
int	is_space(char *str);
int	get_rgb(int r, int g, int b);

// memory_utils.c
void		free_char_array_n(char ***tab, int n);
void		free_char_array(char ***tab);
void		free_str(char **s);
void		close_fd(int *fd);
char		**ft_arrdup(char **tab);

// time_utils.c
size_t	get_time(void);


// main.c
int exit_cleanup(void *param);

#endif