/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:49:58 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 11:37:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (err_mlx(0), 1);
	game->tex.display.img = mlx_new_image(game->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!game->tex.display.img)
		return (err_mlx(1), 1);
	game->tex.display.addr = mlx_get_data_addr(game->tex.display.img,
			&game->tex.display.bits_per_pixel, &game->tex.display.line_length,
			&game->tex.display.endian);
	if (!game->tex.display.addr)
		return (err_mlx(2), 1);
	return (0);
}

int	create_window(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, SCREENWIDTH, SCREENHEIGHT,
			"Zelsky One");
	if (!game->mlx_win)
		return (err_mlx(0), 1);
	return (0);
}
