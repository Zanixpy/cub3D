/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:49:58 by omawele           #+#    #+#             */
/*   Updated: 2026/07/06 16:34:16 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int init_texture(t_game *game)
{
    int width;
    int height;

    game->texture[0] = mlx_png_file_to_image(game->mlx, game->NO_texture, &width, &height);
    if (!game->texture[0])
        return (1);
    game->texture[1] = mlx_png_file_to_image(game->mlx, game->SO_texture, &width, &height);
    if (!game->texture[1])
        return (1);
    game->texture[2] = mlx_png_file_to_image(game->mlx, game->EA_texture, &width, &height);
    if (!game->texture[2])
        return (1);
    game->texture[3] = mlx_png_file_to_image(game->mlx, game->WE_texture, &width, &height);
    if (!game->texture[3])
        return (1);
    return (0);  
}

int init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (err_mlx(0), 1);
    game->mlx_win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, "Zelsky One");
    if (!game->mlx_win)
        return (err_mlx(0), 1);
    if (init_texture(game))
        return(err_mlx(1), 1);
    return (0);
}




