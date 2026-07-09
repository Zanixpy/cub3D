/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:32:40 by omawele           #+#    #+#             */
/*   Updated: 2026/07/09 12:37:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void set_math_values(t_game *game)
{
    game->planX = 0.66;
    game->planY = 0;
    game->dirX = 0;
    game->dirY = 0;
    if (game->player_direction == 'E')
        game->dirX = 1;
    else if (game->player_direction == 'W')
        game->dirX = -1;
    else if (game->player_direction == 'N')
        game->dirY == 1;
    else if (game->player_direction == 'S')
        game->dirY == -1;
}

/*
** Initialize ray direction for screen column x
** camera_x: -1 (left) to +1 (right), ray_dir = player_dir + plane * camera_x
** delta_dist: distance ray travels between grid lines
*/
void    init_ray(t_game *game, int x)
{
    game->cameraX = 2 * x / (double)SCREENWIDTH - 1;
    game->dirX = game->dirX + game->planX * game->cameraX;
    game->dirY = game->dirX + game->planY * game->cameraY;
    game->map_x = (int)game->posX;
    game->map_y = (int)game->posY;
    if (game->dirX == 0)
        game->delta_dist_x = 1e30;
    else
        game->delta_dist_x = fabs(1 / game->dir_x);
    if (game->dir_y == 0)
        game->delta_dist_y = 1e30;
    else
        game->delta_dist_y = fabs(1 / game->dir_y);
    game->hit = 0;
}

/*
** Calculate step direction (+1 or -1) and initial side distances
** side_dist: distance from player position to next grid line
*/
static void    calculate_step(t_ray *ray, t_player *player)
{
    if (ray->dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
            * ray->delta_dist_x;
    }
    if (ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
            * ray->delta_dist_y;
    }
}