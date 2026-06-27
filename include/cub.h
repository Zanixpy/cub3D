/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:21:29 by omawele           #+#    #+#             */
/*   Updated: 2026/06/27 22:39:03 by omawele          ###   ########.fr       */
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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include <errno.h>

/* ===================================
 MACRO
=================================== */

# define SPACE ' '
# define WALL 1
# define EMPSPACE 0
# define PLAYER_DIR 'N' || 'S' || 'E' || 'W'
# define ERRMALLOC 15


/* ===================================
 STRUCT 
=================================== */

typedef struct s_game
{
    char **map;
    int fd;
    
    void *mlx;
    void *mlx_win;
    
    char player_direction;  
    int pos_xy[2];
    
    char *brut_texture[4];
    void *texture[4];

    int floor_RGB[3];
    int ceiling_RGB[3];
    
} t_game;

// struct_handling.c
t_game *struct_init(void);
void struct_destroy(t_game **game);


/* ===================================
 PARSER
=================================== */


// parser_errors.c
void exit_err_parser(int code);

// parser.c


/* ===================================
 UTILS
=================================== */

// utils.c
int	ft_strcmp(const char *s1, const char *s2);
int	array_size(char **tab);

// memory_utils.c
void	free_char_array_n(char ***tab, int n);
void	free_char_array(char ***tab);
void	free_str(char **s);




 
#endif