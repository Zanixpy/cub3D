/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 11:44:54 by omawele           #+#    #+#             */
/*   Updated: 2026/07/07 17:33:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int handleMoves(void *param)
{
    t_data  floor;
    t_data  player;
    int playerc;
    int floorc;
    t_game *game;
    int x;
    int y;

    game = (t_game *)param;
    
    player.img = mlx_new_image(game->mlx, 16, 16);
    if (!player.img)
        return (1);
    player.addr = mlx_get_data_addr(player.img, &player.bits_per_pixel, &player.line_length, &player.endian);
    if (!player.addr)
        return (1); 
    playerc = create_rgb(232, 27, 27);
    floor.img = mlx_new_image(game->mlx, 16, 16);
    if (!floor.img)
        return (1);
    floor.addr = mlx_get_data_addr(floor.img, &floor.bits_per_pixel, &floor.line_length, &floor.endian);
    if (!floor.addr)
        return (1);
    floorc = create_rgb(228, 228, 130);    
    y = 0;
    while (y < 16)
    {
        x = 0;
        while (x < 16)
        {
            my_mlx_pixel_put(&player, x, y, playerc);
            my_mlx_pixel_put(&floor, x, y, floorc); 
            x++;
        }
        y++;   
    }    
    if (game->foward)
    {
        if (game->map[(int)(game->posY - 0.01)][(int)game->posX] != 1)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, floor.img, (int)game->posX * 32, (int)game->posY * 32);      
            game->posY -= 0.01;
            mlx_put_image_to_window(game->mlx, game->mlx_win, player.img, (int)game->posX * 32, (int)game->posY * 32);          
        }
  
    }
    if (game->right)
    {
        if (game->map[(int)game->posY][(int)(game->posX + 0.01)] != 1)
        {            
            mlx_put_image_to_window(game->mlx, game->mlx_win, floor.img, (int)game->posX * 32, (int)game->posY * 32);      
            game->posX += 0.01; 
            mlx_put_image_to_window(game->mlx, game->mlx_win, player.img, (int)game->posX * 32, (int)game->posY * 32);   
        }
        
    }
    if (game->left)
    {
        if (game->map[(int)game->posY][(int)(game->posX - 0.01)] != 1)
        {            
            mlx_put_image_to_window(game->mlx, game->mlx_win, floor.img, (int)game->posX * 32, (int)game->posY * 32);      
            game->posX -= 0.01;
            mlx_put_image_to_window(game->mlx, game->mlx_win, player.img, (int)(game->posX) * 32, (int)game->posY * 32);
        }      
    }
    if (game->backwards)
    {
        if (game->map[(int)(game->posY + 0.01)][(int)game->posX] != 1)
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, floor.img, (int)game->posX * 32, (int)game->posY * 32);      
            game->posY += 0.01;
            mlx_put_image_to_window(game->mlx, game->mlx_win, player.img, (int)game->posX * 32, (int)game->posY * 32);      
        }
    }
    return (0);
}


int handleKeyPress(int keycode, void *param)
{
    t_game *game;

    game = (t_game *)param;   
    if (keycode == 13)
        game->foward = 1;
    else if (keycode == 0)
        game->left = 1;
    else if (keycode == 1)
        game->backwards = 1;
    else if (keycode == 2)
        game->right = 1;
    return (0);
}


int handleKeyRelease(int keycode, void *param)
{
    t_game *game;

    game = (t_game *)param;   
    if (keycode == 13)
        game->foward = 0;
    else if (keycode == 0)
        game->left = 0;
    else if (keycode == 1)
        game->backwards = 0;
    else if (keycode == 2)
        game->right = 0;
    return (0);
}
