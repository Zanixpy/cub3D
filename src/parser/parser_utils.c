/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:19:39 by omawele           #+#    #+#             */
/*   Updated: 2026/06/27 22:46:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int fill_data(t_game *game)
{
    char *line;
    
    line = get_next_line(game->fd);
    while (line)
    {
        if (ft_strnstr(line, "NO", ft_strlen(line)))
            
        /* code */
    }
}


void get_texture(char *line)


int fill_map(t_game *game);