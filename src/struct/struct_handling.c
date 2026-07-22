/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:31:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:46:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	struct_destroy_data(t_game *game)
{
	free_char_array(&game->map);
	free_str(&game->filename);
	if (game->tex.no_texture.img)
		mlx_destroy_image(game->mlx, game->tex.no_texture.img);
	if (game->tex.so_texture.img)
		mlx_destroy_image(game->mlx, game->tex.so_texture.img);
	if (game->tex.we_texture.img)
		mlx_destroy_image(game->mlx, game->tex.we_texture.img);
	if (game->tex.ea_texture.img)
		mlx_destroy_image(game->mlx, game->tex.ea_texture.img);
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
	tmp->p.move_speed = 3.0;
	tmp->p.rot_speed = 2.5;
	tmp->p.backward = 0;
	tmp->p.right = 0;
	tmp->p.foward = 0;
	tmp->p.left = 0;
	tmp->p.rotate_right = 0;
	tmp->p.rotate_left = 0;
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
