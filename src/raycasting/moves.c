/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:08:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/25 16:25:04 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	frame_speed;

	frame_speed = game->p.move_speed * game->delta_time;
	new_x = game->pos_x + game->dir_x * frame_speed;
	new_y = game->pos_y + game->dir_y * frame_speed;
	if (!is_wall(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (!is_wall(game, game->pos_x, new_y))
		game->pos_y = new_y;
}

void	go_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	frame_speed;

	frame_speed = game->p.move_speed * game->delta_time;
	new_x = game->pos_x - game->dir_x * frame_speed;
	new_y = game->pos_y - game->dir_y * frame_speed;
	if (!is_wall(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (!is_wall(game, game->pos_x, new_y))
		game->pos_y = new_y;
}

void	go_right(t_game *game)
{
	double	new_x;
	double	new_y;
	double	frame_speed;

	frame_speed = game->p.move_speed * game->delta_time;
	new_x = game->pos_x - game->dir_y * frame_speed;
	new_y = game->pos_y + game->dir_x * frame_speed;
	if (!is_wall(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (!is_wall(game, game->pos_x, new_y))
		game->pos_y = new_y;
}

void	go_left(t_game *game)
{
	double	new_x;
	double	new_y;
	double	frame_speed;

	frame_speed = game->p.move_speed * game->delta_time;
	new_x = game->pos_x + game->dir_y * frame_speed;
	new_y = game->pos_y - game->dir_x * frame_speed;
	if (!is_wall(game, new_x, game->pos_y))
		game->pos_x = new_x;
	if (!is_wall(game, game->pos_x, new_y))
		game->pos_y = new_y;
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = -game->p.rot_speed * game->delta_time;
	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
	game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
}
