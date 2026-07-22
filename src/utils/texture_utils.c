/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:34:25 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:35:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_tex_color(t_data *tex, int tex_x, int tex_y)
{
	char	*pixel;

	if (tex_x < 0 || tex_x >= TEXWIDTH || tex_y < 0 || tex_y >= TEXHEIGHT)
		return (0);
	pixel = tex->addr + (tex_y * tex->line_length + tex_x * (tex->bits_per_pixel
				/ 8));
	return (*(int *)pixel);
}

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
