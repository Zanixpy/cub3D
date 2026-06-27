/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:31:29 by omawele           #+#    #+#             */
/*   Updated: 2026/06/27 22:26:34 by omawele          ###   ########.fr       */
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
    tmp->brut_texture[0] = NULL;
    tmp->brut_texture[1] = NULL;
    tmp->brut_texture[2] = NULL;
    tmp->brut_texture[3] = NULL;
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
    free(*game);
    *game = NULL;
}
