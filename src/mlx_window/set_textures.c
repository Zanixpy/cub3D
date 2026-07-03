/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:17:01 by omawele           #+#    #+#             */
/*   Updated: 2026/07/03 12:56:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void fill_window(t_data *data, int floor_color, int ceiling_color)
{
    int y;
    int x;
    
    y = 0;
    while (y < SCREENHEIGHT)
    {
        x = 0;
        while (x < SCREENWIDTH)
        {
            if (y < SCREENHEIGHT / 2)
                my_mlx_pixel_put(data, x, y, ceiling_color);
            else
                my_mlx_pixel_put(data, x, y, floor_color);
            x++;
        }
        y++;
    }
}

int set_floor_ceiling(t_game *game)
{
    t_data  data;
    int floor_color;
    int ceiling_color;

    data.img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
    if (!data.img)
        return (1);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    if (!data.addr)
        return (1);
    floor_color = create_rgb(game->floor_RGB[0], game->floor_RGB[1], game->floor_RGB[2]);
    ceiling_color = create_rgb(game->ceiling_RGB[0], game->ceiling_RGB[1], game->ceiling_RGB[2]);
    fill_window(&data, floor_color, ceiling_color);
    mlx_put_image_to_window(game->mlx, game->mlx_win, data.img, 0, 0);
    return (0);
}
