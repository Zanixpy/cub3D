/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:23:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/02 14:48:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*get_filename(char *filepath)
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

int	get_fd_and_filename(t_game *game, char *av)
{
	int	len;

	game->filename = get_filename(av);
	if (!game->filename)
		return (1);
	len = ft_strlen(game->filename);
	if (ft_strcmp(game->filename + (len - 4), ".cub"))
		return (err_parser(2), 1);
	game->fd = open(game->filename, O_RDONLY);
	if (game->fd == -1)
		return (err_parser(4), 1);
	return (0);
}


