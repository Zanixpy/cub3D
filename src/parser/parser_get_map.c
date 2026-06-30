/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:19:39 by omawele           #+#    #+#             */
/*   Updated: 2026/06/30 19:24:05 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_map_element(t_game *game, char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line) - 1;
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

static int	count_line(t_game *game)
{
	char	*line;
	int		count;
	int		fd;
	int		start;

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		return (err_parser(4), -1);
	count = 0;
	start = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (start != 6 && is_element(line))
			start++;
		else if (is_map_element(game, line) && start == 6)
			count++;
		else if (line[0] != '\n')
			return (err_parser(7), close(fd), free(line), -1);
		free(line);
		line = get_next_line(game->fd);
	}
    printf(" count line : %d\n", count);
	return (close(fd), count);
}

static int	init_map(t_game *game)
{
	game->height = count_line(game);
	if (game->height == -1)
		return (1);
	game->fd = open(game->filename, O_RDONLY);
	if (game->fd == -1)
		return (err_parser(4), 1);
	game->map = ft_calloc(game->height, sizeof(char *));
	if (!game->map)
		return (err_parser(3), 1);
	return (0);
}

int	fill_map(t_game *game)
{
	char	*line;
	int		start;
	int		i;

	if (init_map(game))
		return (1);
	line = get_next_line(game->fd);
	start = 0;
	i = 0;
	while (line)
	{
		if (start != 6 && (is_element(line) || line[0] == '\n'))
			start++;
		else if (is_map_element(game, line) && start == 6)
		{
			game->map[i] = clean_str(line, 1);
			if (!game->map[i])
				return (err_parser(3), free(line), free_char_array_n(&game->map,
						i), 1);
			i++;
		}
		free(line);
		line = get_next_line(game->fd);
	}
	return (close_fd(&game->fd), 0);
}
