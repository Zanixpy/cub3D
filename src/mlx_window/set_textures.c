/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 11:17:01 by omawele           #+#    #+#             */
/*   Updated: 2026/07/07 12:19:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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


int set_2D_grid(t_game *game)
{
    t_data  floor;
    t_data  wall;
    t_data  player;
    int floorc;
    int black;
    int random;
    int playerc;
    int x;
    int y;
    
    floor.img = mlx_new_image(game->mlx, 64, 64);
    if (!floor.img)
        return (1);
    floor.addr = mlx_get_data_addr(floor.img, &floor.bits_per_pixel, &floor.line_length, &floor.endian);
    if (!floor.addr)
        return (1);
        
    wall.img = mlx_new_image(game->mlx, 64, 64);
    if (!wall.img)
        return (1);
    wall.addr = mlx_get_data_addr(wall.img, &wall.bits_per_pixel, &wall.line_length, &wall.endian);
    if (!wall.addr)
        return (1);

    player.img = mlx_new_image(game->mlx, 16, 16);
    if (!player.img)
        return (1);
    player.addr = mlx_get_data_addr(player.img, &player.bits_per_pixel, &player.line_length, &player.endian);
    if (!player.addr)
        return (1);   
        
    floorc = create_rgb(228, 228, 130);
    black = create_rgb(20, 20, 20);
    random =  create_rgb(196, 196, 196);
    playerc = create_rgb(232, 27, 27);

    y = 0;
    while (y < 64)
    {
        x = 0;
        while (x < 64)
        {
                my_mlx_pixel_put(&floor, x, y, floorc);
            if (y < 16 && x < 16)
                my_mlx_pixel_put(&player, x, y, playerc);
            if (y == 0 || y == 63 || x == 0 || x == 63)
                my_mlx_pixel_put(&wall, x, y, black);
            else
                my_mlx_pixel_put(&wall, x, y, random);
            x++;
        }
        y++;   
    }
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, wall.img, x * 64, y * 64);
            else if (game->map[y][x] == 'N' || game->map[y][x] == 'S' || game->map[y][x] == 'E' || game->map[y][x] == 'W')
                    mlx_put_image_to_window(game->mlx, game->mlx_win, player.img, x * 32, y * 32);
            else
                mlx_put_image_to_window(game->mlx, game->mlx_win, floor.img, x * 64, y * 64);         
            x++;
        }
        y++;   
    }
    return (0);  
}
