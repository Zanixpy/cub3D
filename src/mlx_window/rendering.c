/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:06:31 by omawele           #+#    #+#             */
/*   Updated: 2026/07/09 12:34:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** Fast pixel drawing: directly write color to image buffer
** Optimized version without bounds checking for inner loops
*/
static inline void    fast_pixel_put(t_data *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

/*
** Safe pixel drawing with bounds checking for edge cases
*/
void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    if (x < 0 || x >= data->screen_w || y < 0 || y >= data->screen_h)
        return ;
    fast_pixel_put(&data->img, x, y, color);
}

/*
** Optimized vertical line drawing with fast pixel access
** Uses fast_pixel_put for internal pixels (no bounds check needed)
*/
void    draw_vertical_line(t_data *data, int x, t_ray *ray)
{
    int    y;

    y = 0;
    while (y < ray->draw_start && y < data->screen_h)
    {
        fast_pixel_put(&data->img, x, y, data->tex.ceiling_color);
        y++;
    }
    y = ray->draw_start;
    while (y <= ray->draw_end && y < data->screen_h)
    {
        fast_pixel_put(&data->img, x, y, get_texture_color(data, ray, y));
        y++;
    }
    y = ray->draw_end + 1;
    while (y < data->screen_h)
    {
        fast_pixel_put(&data->img, x, y, data->tex.floor_color);
        y++;
    }
}

/*
** Render complete frame: perform raycasting then display image
** Called every frame by mlx_loop_hook
*/
void    render_frame(t_data *data)
{
    raycasting(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}