/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 05:29:34 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:36:48 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_release(int code, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (code == 122)
		game->p.foward = 0;
	else if (code == 100)
		game->p.right = 0;
	else if (code == 113)
		game->p.left = 0;
	else if (code == 115)
		game->p.backward = 0;
	else if (code == 65361)
		game->p.rotate_left = 0;
	else if (code == 65363)
		game->p.rotate_right = 0;
	return (0);
}

int	key_hold(int code, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (code == 65307)
		exit_cleanup(param);
	if (code == 122)
		game->p.foward = 1;
	else if (code == 100)
		game->p.right = 1;
	else if (code == 113)
		game->p.left = 1;
	else if (code == 115)
		game->p.backward = 1;
	else if (code == 65361)
		game->p.rotate_left = 1;
	else if (code == 65363)
		game->p.rotate_right = 1;
	return (0);
}

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = game->p.rot_speed * game->delta_time;
	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
	game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
}
