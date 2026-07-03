/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:31:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/03 13:00:43 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	struct_set_content(t_game *tmp)
{
	tmp->posX = 0;
	tmp->posY = 0;
	tmp->dirX = 0;
	tmp->dirY = 0;
	tmp->planeX = 0;
	tmp->planeY = 0;
    tmp->texture[0] = NULL;
    tmp->texture[1] = NULL;
    tmp->texture[2] = NULL;
    tmp->texture[3] = NULL;
}

static void	struct_destroy_data(t_game *game)
{
	close_fd(&game->fd);
	if (game->map)
		free_char_array(&game->map);
	if (game->NO_texture)
		free(game->NO_texture);
	if (game->SO_texture)
		free(game->SO_texture);
	if (game->WE_texture)
		free(game->WE_texture);
	if (game->EA_texture)
		free(game->EA_texture);
	if (game->filename)
		free(game->filename);
	if (game->texture[0])
		mlx_destroy_image(game->mlx, game->texture[0]);
	if (game->texture[1])
		mlx_destroy_image(game->mlx, game->texture[1]);
	if (game->texture[2])
		mlx_destroy_image(game->mlx, game->texture[2]);
	if (game->texture[3])
		mlx_destroy_image(game->mlx, game->texture[3]);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		free(game->mlx);
}

t_game	*struct_init(void)
{
	t_game	*tmp;

	tmp = malloc(sizeof(t_game));
	if (!tmp)
		return (NULL);
	tmp->floor_RGB[0] = -1;
	tmp->floor_RGB[1] = -1;
	tmp->floor_RGB[2] = -1;
	tmp->ceiling_RGB[0] = -1;
	tmp->ceiling_RGB[1] = -1;
	tmp->ceiling_RGB[2] = -1;
	tmp->NO_texture = NULL;
	tmp->SO_texture = NULL;
	tmp->WE_texture = NULL;
	tmp->EA_texture = NULL;
	tmp->filename = NULL;
	tmp->height = 0;
	tmp->width = 0;
	tmp->player_direction = 0;
	tmp->fd = -2;
    tmp->map = NULL;
    tmp->mlx = NULL;
    tmp->mlx_win = NULL;
	struct_set_content(tmp);
	return (tmp);
}

void	struct_destroy(t_game **game)
{
	if (!game || !(*game))
		return ;
	struct_destroy_data(*game);
	free(*game);
	*game = NULL;
}
