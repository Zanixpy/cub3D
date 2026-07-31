/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 07:26:17 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 09:15:42 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_space(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != SPACE && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

int	is_wall(t_game *game, double x, double y)
{
	int	ix;
	int	iy;

	iy = (int)y;
	ix = (int)x;
	if (iy < 0 || iy >= game->height)
		return (1);
	if (ix < 0 || ix >= (int)ft_strlen(game->map[iy]))
		return (1);
	if (game->map[iy][ix] == '1')
		return (1);
	return (0);
}

int	is_map_element(t_game *game, char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line) - 1;
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (line[i] != SPACE && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (0);
		i++;
	}
	if (game->width < i)
		game->width = i;
	return (1);
}

int	is_element(char *line)
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

int	is_element_complete(t_texture *tex)
{
	if (tex->floor == -1 || tex->ceiling == -1 || !tex->no_texture.img
		|| !tex->so_texture.img || !tex->we_texture.img || !tex->ea_texture.img)
		return (0);
	return (1);
}
