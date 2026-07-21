/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:08:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/21 05:34:15 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void    go_foward(t_game *game)
{
    double    new_x;
    double    new_y;
    double    frame_speed;

    frame_speed = game->p.move_speed * game->delta_time;
    new_x = game->pos_x + game->dir_x * frame_speed;
    new_y = game->pos_y + game->dir_y * frame_speed;
    if (game->map[(int)game->pos_y][(int)new_x] != '1')
        game->pos_x = new_x;
    if (game->map[(int)new_y][(int)game->pos_x] != '1')
        game->pos_y = new_y;
}

// Move backward
void    go_backward(t_game *game)
{
    double    new_x;
    double    new_y;
    double    frame_speed;

    frame_speed = game->p.move_speed * game->delta_time;
    new_x = game->pos_x - game->dir_x * frame_speed;
    new_y = game->pos_y - game->dir_y * frame_speed;
    if (game->map[(int)game->pos_y][(int)new_x] != '1')
        game->pos_x = new_x;
    if (game->map[(int)new_y][(int)game->pos_x] != '1')
        game->pos_y = new_y;
}
// Move right
// Perpendicular vector: (-dir_y, dir_x)
void    go_right(t_game *game)
{
    double    new_x;
    double    new_y;
    double    frame_speed;

    frame_speed = game->p.move_speed * game->delta_time;
    new_x = game->pos_x - game->dir_y * frame_speed;
    new_y = game->pos_y + game->dir_x * frame_speed;
    if (game->map[(int)game->pos_y][(int)new_x] != '1')
        game->pos_x = new_x;
    if (game->map[(int)new_y][(int)game->pos_x] != '1')
        game->pos_y = new_y;
}

// Move left 
// Perpendicular vector: (dir_y, -dir_x)
void    go_left(t_game *game)
{
    double    new_x;
    double    new_y;
    double    frame_speed;

    frame_speed = game->p.move_speed * game->delta_time;
    new_x = game->pos_x + game->dir_y * frame_speed;
    new_y = game->pos_y - game->dir_x * frame_speed;
    if (game->map[(int)game->pos_y][(int)new_x] != '1')
        game->pos_x = new_x;
    if (game->map[(int)new_y][(int)game->pos_x] != '1')
        game->pos_y = new_y;
}
void    rotate_left(t_game *game)
{
    double    old_dir_x;
    double    old_plane_x;

    old_dir_x = game->dir_x;
    game->dir_x = game->dir_x * cos(-game->p.rot_speed)
        - game->dir_y * sin(-game->p.rot_speed);
    game->dir_y = old_dir_x * sin(-game->p.rot_speed)
        + game->dir_y * cos(-game->p.rot_speed);
    old_plane_x = game->plane_x;
    game->plane_x = game->plane_x * cos(-game->p.rot_speed)
        - game->plane_y * sin(-game->p.rot_speed);
    game->plane_y = old_plane_x * sin(-game->p.rot_speed)
        + game->plane_y * cos(-game->p.rot_speed);
}






