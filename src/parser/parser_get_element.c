/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 17:28:07 by omawele           #+#    #+#             */
/*   Updated: 2026/06/30 18:31:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*extract_texture_path(char *line)
{
	char	**tab;
	char	*tmp;

	tmp = clean_str(line, 0);
	if (!tmp)
		return (err_parser(3), NULL);
	tab = ft_split(tmp, SPACE);
	if (!tab)
		return (err_parser(3), free(tmp), NULL);
	free(tmp);
	if (array_size(tab) != 2)
	{
		free_char_array(&tab);
		return (err_parser(5), NULL);
	}
	tmp = ft_strdup(tab[1]);
	free_char_array(&tab);
	if (!tmp)
		return (err_parser(3), NULL);
	return (tmp);
}

static char	**extract_color(char *line)
{
	char	**tab;
	char	*tmp;
	int		i;

	tmp = clean_str(line, 0);
	if (!tmp)
		return (err_parser(3), NULL);
	i = 1;
	while (tmp[i] && tmp[i] == SPACE)
		i++;
	if (tmp[i] == '\0' || !ft_isdigit(tmp[i]))
		return (free(tmp), err_parser(5), NULL);
	if (!is_RGB(tmp + i))
		return (free(tmp), err_parser(6), NULL);
	tab = ft_split(tmp + i, ',');
	free(tmp);
	if (!tab)
		return (err_parser(3), NULL);
	return (tab);
}

static int	get_texture(t_game *game, char *line, int ret)
{
	char	*tmp;

	tmp = extract_texture_path(line);
	if (!tmp)
		return (1);
	if (ret == 1 && !game->NO_texture)
		game->NO_texture = tmp;
	else if (ret == 2 && !game->SO_texture)
		game->SO_texture = tmp;
	else if (ret == 3 && !game->WE_texture)
		game->WE_texture = tmp;
	else if (ret == 4 && !game->EA_texture)
		game->EA_texture = tmp;
	else
		return (err_parser(5), free(tmp), 1);
	return (0);
}

static int	get_color(t_game *game, char *line, int ret)
{
	char	**tmp;

	tmp = extract_color(line);
	if (!tmp)
		return (1);
	if (ret == 5 && game->floor_RGB[0] == -1 && game->floor_RGB[1] == -1
		&& game->floor_RGB[2] == -1)
	{
		game->floor_RGB[0] = ft_atoi(tmp[0]);
		game->floor_RGB[1] = ft_atoi(tmp[1]);
		game->floor_RGB[2] = ft_atoi(tmp[2]);
	}
	else if (ret == 6 && game->ceiling_RGB[0] == -1 && game->ceiling_RGB[1] ==
		-1 && game->ceiling_RGB[2] == -1)
	{
		game->ceiling_RGB[0] = ft_atoi(tmp[0]);
		game->ceiling_RGB[1] = ft_atoi(tmp[1]);
		game->ceiling_RGB[2] = ft_atoi(tmp[2]);
	}
	else
		return (err_parser(5), free_char_array(&tmp), 1);
	free_char_array(&tmp);
	return (0);
}

int	fill_data(t_game *game)
{
	char	*line;
	int		ret;

	line = get_next_line(game->fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			ret = is_element(line);
			if (ret > 0 && ret < 5 && !is_element_complete(game))
				ret = get_texture(game, line, ret);
			else if ((ret == 5 || ret == 6) && !is_element_complete(game))
				ret = get_color(game, line, ret);
			else if (!is_map_element(game, line))
				return (err_parser(5), free(line), 1);
			if (ret)
				return (free(line), ret);
		}
		free(line);
		line = get_next_line(game->fd);
	}
	return (close_fd(&game->fd), 0);
}
