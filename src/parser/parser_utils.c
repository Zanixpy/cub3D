/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:23:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/01 15:15:46 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_RGB_utils(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			count++;
			while (str[i] && ft_isdigit(str[i]))
				i++;
			if (str[i] == ',')
				i++;
		}
		else
			return (0);
	}
	if (count != 3)
		return (0);
	return (1);
}

int	is_RGB(char *str)
{
	int	i;
	int	nb;

	if (!is_RGB_utils(str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			nb = 0;
			while (str[i] && ft_isdigit(str[i]))
			{
				nb = 10 * nb + (str[i] - '0');
				i++;
			}
			if (nb > 255 || nb < 0)
				return (0);
		}
        else
		    i++;
	}
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

int	is_element_complete(t_game *game)
{
	if (game->floor_RGB[0] == -1 || game->floor_RGB[1] == -1
		|| game->floor_RGB[2] == -1)
		return (0);
	if (game->ceiling_RGB[0] == -1 || game->ceiling_RGB[1] == -1
		|| game->ceiling_RGB[2] == -1)
		return (0);
	if (!game->NO_texture || !game->EA_texture || !game->WE_texture
		|| !game->SO_texture)
		return (0);
	return (1);
}

char	*get_filename(char *filepath)
{
	char	**tab;
	char	*tmp;
	int		len;

	len = ft_strlen(filepath);
	if (len < 5)
		return (err_parser(2), NULL);
	if (ft_strchr(filepath, '/'))
	{
		tab = ft_split(filepath, '/');
		if (!tab)
			return (err_parser(3), NULL);
        if (ft_strlen(tab[array_size(tab) - 1]) < 5)
		    return (err_parser(2), free_char_array(&tab), NULL);
        free_char_array(&tab);
	}
	tmp = ft_strdup(filepath);
	if (!tmp)
		return (err_parser(3), NULL);
	return (tmp);
}
