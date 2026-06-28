/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:28:07 by omawele           #+#    #+#             */
/*   Updated: 2026/06/28 18:57:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


static char *extract_texture_path(char *line)
{
    char **tab;
    char *tmp;

    tmp = ft_strtrim(line, " ");
    if (!tmp)
        return (NULL);
    tab = ft_split(tmp, SPACE);
    if (!tab)
        return (free(tmp), NULL);
    free(tmp);
    if (array_size(tab) != 2)
    {
        free_char_array(&tab);
        return (NULL);
    }
    tmp = ft_strdup(tab[1]);
    free_char_array(&tab);
    if (!tmp)
        return (NULL);
    return (tmp);
}

static char **extract_color(char *line)
{
    char **tab;
    char *tmp;
    int i;
    
    tmp = ft_strtrim(line, " ");
    if (!tmp)
        return (NULL);
    i = 1;
    while (tmp[i] && tmp[i] == SPACE)
        i++;
    if (tmp[i] == '\0')
        return (free(tmp), NULL);
    if (is_RGB(tmp + i))
        
    return (tab);
}


static int get_texture(t_game *game, char *line, int ret)
{
    char *tmp;

    tmp = extract_texture_path(line);
    if (!tmp)
        return (ERRMALLOC);
    if (ret == 1 && !game->NO_texture)
        game->NO_texture = tmp;
    else if (ret == 2 && !game->SO_texture)
        game->SO_texture = tmp;
    else if (ret == 3 && !game->WE_texture)
        game->WE_texture = tmp;
    else if (ret == 4 && !game->NO_texture)
        game->EA_texture = tmp;
    else
        return (free(tmp), 1);
    return (0);   
}

static int get_color(t_game *game, char *line, int ret)
{
    char **tmp;

    tmp = extract_color(line);
    if (!tmp)
        return (ERRMALLOC);
    if (ret == 5 && game->floor_RGB[0] == -1 && game->floor_RGB[1] == -1 && game->floor_RGB[2] == -1)
    {
        game->floor_RGB[0] = ft_atoi(tmp[0]);
        game->floor_RGB[1] = ft_atoi(tmp[1]);
        game->floor_RGB[2] = ft_atoi(tmp[2]);  
    }
    else if (ret == 6 && game->ceiling_RGB[0] == -1 && game->ceiling_RGB[1] == -1 && game->ceiling_RGB[2] == -1)
    {
        game->ceiling_RGB[0] = ft_atoi(tmp[0]);
        game->ceiling_RGB[1] = ft_atoi(tmp[1]);
        game->ceiling_RGB[2] = ft_atoi(tmp[2]); 
    }
    else
        return (free_char_array(&tmp), 1);
    free_char_array(&tmp);
    return (0);
}

int fill_data(t_game *game)
{
    char *line;
    int ret;
    
    line = get_next_line(game->fd);
    while (line)
    {
        if (line[0] != '\n')
        {
            ret = is_element(line);
            if (ret > 0 && ret < 5)
                ret = get_texture(game, line, ret);
            else if (ret == 5 || ret == 6)
                ret = get_color(game, line, ret);
            else
                return (free(line), 1);
            if (ret)
                return (free(line), ret);
        }
        free(line);
        line = get_next_line(game->fd);
    }
    return (0);
}
