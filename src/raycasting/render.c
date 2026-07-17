/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:05:09 by omawele           #+#    #+#             */
/*   Updated: 2026/07/17 14:12:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_vertical_line(t_game *game, int x)
{
    int y;
    int floor;
    int ceiling;

    y = 0;
    floor = get_rgb(game->floor_RGB[0], game->floor_RGB[1], game->floor_RGB[2]);
    ceiling = get_rgb(game->ceiling_RGB[0], game->ceiling_RGB[1], game->ceiling_RGB[2]);
    while (y < game->draw_start && y < SCREENHEIGHT)
    {
        my_mlx_pixel_put(&game->img, x, y, ceiling);
        y++;        
    }
    y = game->draw_start;
    if (y < 0)
        y = 0;
    while (y <= game->draw_end && y < SCREENHEIGHT)
    {
        my_mlx_pixel_put(&game->img, x, y, ceiling);
        y++;
    }
    y = game->draw_end + 1;
    while (y < SCREENHEIGHT)
    {
        my_mlx_pixel_put(&game->img, x, y, floor);
        y++;
    }
}

int render_graphics(void *param)
{
    t_game *game;

    game = (t_game *)param;
    raycasting(game);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
    return (0);
}