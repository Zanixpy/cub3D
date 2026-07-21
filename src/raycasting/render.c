/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:05:09 by omawele           #+#    #+#             */
/*   Updated: 2026/07/21 05:48:12 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int get_tex_color(t_data *tex, int tex_x, int tex_y)
{
    char    *pixel;
    int     color;

    if (tex_x < 0 || tex_x >= SCREENWIDTH || tex_y < 0 || tex_y >= SCREENHEIGHT)
        return (0);
    
    pixel = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bits_per_pixel / 8));
    color = *(int *)pixel;
    return (color);
}

void texturing_calculations(t_game *game)
{
    int line_height;

    line_height = game->draw_end - game->draw_start;
    if (game->side == 0)
        game->wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
    else
        game->wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
    game->wall_x -= floor(game->wall_x);
    game->tex_x = (int)(game->wall_x * (double)TEXWIDTH);
    game->step = 1.0 * TEXHEIGHT / line_height;
    game->tex_pos = (game->draw_start - SCREENHEIGHT / 2 + line_height / 2) * game->step;
}

void draw_vertical_line(t_game *game, int x)
{
    int y;
    
    y = 0;
    texturing_calculations(game);
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
        game->tex_y = (int)game->tex_pos % (TEXHEIGHT - 1);
        game->tex_pos += game->step;
        my_mlx_pixel_put(&game->tex.display, x, y, get_tex_color(&game->tex.NO_texture, x, game->tex_y));
        y++;
    }
    y = game->draw_end + 1;
    while (y < SCREENHEIGHT)
    {
        my_mlx_pixel_put(&game->tex.display, x, y, game->tex.floor);
        y++;
    }
}

int render_graphics(void *param)
{
    t_game *game;

    game = (t_game *)param;
    raycasting(game);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->tex.display.img, 0, 0);
    return (0);
}