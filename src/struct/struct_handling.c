/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:31:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/13 01:23:00 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static void mlx_cleanup(t_game *game)
{
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

static void	struct_destroy_data(t_game *game)
{
	free_char_array(&game->map);
	free_str(&game->NO_texture);
	free_str(&game->SO_texture);
	free_str(&game->WE_texture);
	free_str(&game->EA_texture);
	free_str(&game->filename);
	if (game->texture[0])
		mlx_destroy_image(game->mlx, game->texture[0]);
	if (game->texture[1])
		mlx_destroy_image(game->mlx, game->texture[1]);
	if (game->texture[2])
		mlx_destroy_image(game->mlx, game->texture[2]);
	if (game->texture[3])
		mlx_destroy_image(game->mlx, game->texture[3]);
	mlx_cleanup(game);
}

t_game	*struct_init(void)
{
	t_game	*tmp;

	tmp = ft_calloc(1, sizeof(t_game));
	if (!tmp)
		return (NULL);
	tmp->floor_RGB[0] = -1;
	tmp->floor_RGB[1] = -1;
	tmp->floor_RGB[2] = -1;
	tmp->ceiling_RGB[0] = -1;
	tmp->ceiling_RGB[1] = -1;
	tmp->ceiling_RGB[2] = -1;
	tmp->height = 0;
	tmp->width = 0;
	tmp->texture[0] = NULL;
    tmp->texture[1] = NULL;
    tmp->texture[2] = NULL;
    tmp->texture[3] = NULL;
	tmp->pos_x = 0;
	tmp->pos_y = 0;
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
