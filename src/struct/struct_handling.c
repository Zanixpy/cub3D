/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:31:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/21 05:40:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static void	struct_destroy_data(t_game *game)
{
	free_char_array(&game->map);
	free_str(&game->filename);
	if (game->tex.NO_texture.img)
		mlx_destroy_image(game->mlx, game->tex.NO_texture.img);
	if (game->tex.SO_texture.img)
		mlx_destroy_image(game->mlx, game->tex.SO_texture.img);
	if (game->tex.WE_texture.img)
		mlx_destroy_image(game->mlx, game->tex.WE_texture.img);
	if (game->tex.EA_texture.img)
		mlx_destroy_image(game->mlx, game->tex.EA_texture.img);
	if (game->tex.display.img)
		mlx_destroy_image(game->mlx, game->tex.display.img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

t_game	*struct_init(void)
{
	t_game	*tmp;

	tmp = ft_calloc(1, sizeof(t_game));
	if (!tmp)
		return (NULL);
	tmp->tex.floor = -1;
	tmp->tex.ceiling = -1;
	tmp->height = 0;
	tmp->width = 0;
	tmp->pos_x = 0;
	tmp->pos_y = 0;
	tmp->dir_x = 0;
	tmp->dir_y = 0;
	tmp->p.move_speed = 0.05;
	tmp->p.rot_speed = 0.04;
	tmp->p.backward = 0;
	tmp->p.right = 0;
	tmp->p.foward = 0;
	tmp->p.left = 0;
	tmp->p.rotate_right = 0;
	tmp->p.rotate_left = 0;
	tmp->plane_x = 0.0;
	tmp->plane_y = 0.66;
	tmp->frame_time_ms = 0.0;
	tmp->delta_time = 0.0;
	tmp->last_frame = 0.0;
	return (tmp);
}

void	struct_destroy(t_game **game)
{
	if (!game || !(*game))
		return ;
	struct_destroy_data(*game);
	free(*game);
	*game = NULL;
}
