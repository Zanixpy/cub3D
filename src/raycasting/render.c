/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:05:09 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 14:04:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_data	*select_texture(t_game *game)
{
	if (game->side == 0)
	{
		if (game->ray_dir_x > 0)
			return (&game->tex.we_texture);
		return (&game->tex.ea_texture);
	}
	if (game->ray_dir_y > 0)
		return (&game->tex.so_texture);
	return (&game->tex.no_texture);
}

void	texturing_calculations(t_game *game)
{
	if (game->line_height <= 0)
		game->line_height = 1;
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
	else
		game->wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = (int)(game->wall_x * (double)TEXWIDTH);
	if (game->side == 0 && game->ray_dir_x > 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
	if (game->side == 1 && game->ray_dir_y < 0)
		game->tex_x = TEXWIDTH - game->tex_x - 1;
	game->step = 1.0 * TEXHEIGHT / game->line_height;
	game->tex_pos = (game->draw_start - SCREENHEIGHT / 2 + game->line_height
			/ 2) * game->step;
}

void	draw_vertical_line(t_game *game, int x)
{
	int		y;
	t_data	*tex;

	y = 0;
	texturing_calculations(game);
	tex = select_texture(game);
	while (y < game->draw_start && y < SCREENHEIGHT)
	{
		my_mlx_pixel_put(&game->tex.display, x, y, game->tex.ceiling);
		y++;
	}
	y = game->draw_start;
	if (y < 0)
		y = 0;
	while (y <= game->draw_end && y < SCREENHEIGHT)
	{
		game->tex_y = (int)game->tex_pos % TEXHEIGHT;
		game->tex_pos += game->step;
		my_mlx_pixel_put(&game->tex.display, x, y, get_tex_color(tex,
				game->tex_x, game->tex_y));
		y++;
	}
	y = game->draw_end;
	while (++y < SCREENHEIGHT)
		my_mlx_pixel_put(&game->tex.display, x, y, game->tex.floor);
}

int	render_graphics(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->tex.display.img, 0,
		0);
	return (0);
}
