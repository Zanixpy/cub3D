/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:06:59 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:36:28 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	create_ray(t_game *game, int x)
{
	game->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	game->map_x = (int)game->pos_x;
	game->map_y = (int)game->pos_y;
	if (game->ray_dir_x == 0)
		game->delta_dist_x = 1e30;
	else
		game->delta_dist_x = fabs(1 / game->ray_dir_x);
	if (game->ray_dir_y == 0)
		game->delta_dist_y = 1e30;
	else
		game->delta_dist_y = fabs(1 / game->ray_dir_y);
	game->hit = 0;
}

void	calculate_step(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x)
			* game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y)
			* game->delta_dist_y;
	}
}

void	dda_algorithm(t_game *game)
{
	calculate_step(game);
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map_y >= 0 && game->map_y < game->height && game->map_x >= 0
			&& game->map_x < game->width)
		{
			if (game->map[game->map_y][game->map_x] == '1')
				game->hit = 1;
		}
		else
			game->hit = 1;
	}
}

void	get_wall_height(t_game *game)
{
	if (game->side == 0)
		game->perp_wall_dist = game->side_dist_x - game->delta_dist_x;
	else
		game->perp_wall_dist = game->side_dist_y - game->delta_dist_y;
	if (game->perp_wall_dist < 0.0001)
		game->perp_wall_dist = 0.0001;
	game->line_height = (int)(SCREENHEIGHT / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + SCREENHEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + SCREENHEIGHT / 2;
	if (game->draw_end >= SCREENHEIGHT)
		game->draw_end = SCREENHEIGHT - 1;
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		create_ray(game, x);
		dda_algorithm(game);
		get_wall_height(game);
		draw_vertical_line(game, x);
		x++;
	}
}
