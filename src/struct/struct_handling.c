/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:31:29 by omawele           #+#    #+#             */
/*   Updated: 2026/06/28 17:13:23 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


t_game *struct_init(void)
{
    t_game *tmp;

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
    return (tmp);
}

void struct_destroy(t_game **game)
{
    if ((*game)->map)
        free_char_array(&(*game)->map);
    if ((*game)->mlx_win)
        mlx_destroy_window((*game)->mlx, (*game)->mlx_win);
    if ((*game)->mlx)
        free((*game)->mlx);
    if ((*game)->fd > -1)
        close((*game)->fd);
    if ((*game)->NO_texture)
        free((*game)->NO_texture);
    if ((*game)->SO_texture)
        free((*game)->SO_texture);
    if ((*game)->WE_texture)
        free((*game)->WE_texture);
    if ((*game)->EA_texture)
        free((*game)->EA_texture);
    free(*game);
    *game = NULL;
}
