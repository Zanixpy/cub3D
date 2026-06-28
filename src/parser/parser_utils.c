/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:23:29 by omawele           #+#    #+#             */
/*   Updated: 2026/06/28 18:49:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int is_element(char *line)
{    
    while (*line)
    {
        if (ft_isalpha(*line))
        {
            if (!ft_strncmp(line, "NO ", 3))
                return (1);
            else if (!ft_strncmp(line, "SO ", 3))
                return (2);
            else if (!ft_strncmp(line, "WE ", 3))
                return (3);
            else if (!ft_strncmp(line, "EA ", 3))
                return (4);
            else if (!ft_strncmp(line, "F ", 2))
                return (5);
            else if (!ft_strncmp(line, "C ", 2))
                return (6);
            else
                return (0);
        }
        else if (*line != SPACE)
            return (0);
        line++;
    }
    return (0);
}

int is_RGB(char *str)
{
    int count;
    int i;
    int nb;

    count = 0;
    i = 0;
    nb = 0;
    while (1)
    {
        if (ft_isdigit(str[i]))
        {
            count++;
            while (str[i] && ft_isdigit(str[i]))
            {
                nb = 10 * nb + (str[i] - '0');
                i++;
            }
            if(nb > 255)
                return (0);
        }
        else if (!(str[i] == ',' && ft_isdigit(str[i + 1]) && ft_isdigit(str[i - 1])))
            return (0);
        i++;
    }
    return (1);
}
