/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 22:19:39 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:39:27 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	count_line(t_game *game)
{
	char	*line;
	int		count;
	int		fd;
	int		start;

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		return (err_parser(3), -1);
	count = 0;
	start = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (start != 6 && is_element(line))
			start++;
		else if (is_map_element(game, line) && start == 6 && (line[0] != '\n'
				|| !is_space(line)))
			count++;
		else if ((line[0] != '\n' && !is_space(line)) || count > 0)
			return (err_parser(6), close(fd), free(line), get_next_line(-1),
				-1);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), count);
}

static int	get_map(t_game *game, int fd, int start)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (start != 6 && is_element(line))
			start++;
		else if (is_map_element(game, line) && start == 6 && line[0] != '\n'
			&& !is_space(line))
		{
			game->map[i] = clean_str(line, 1);
			if (!game->map[i])
				return (err_parser(2), free(line), close(fd), get_next_line(-1),
					free_char_array_n(&game->map, i), 1);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (i == 0)
		return (err_parser(6), close(fd), 1);
	return (close(fd), 0);
}

int	load_map(t_game *game)
{
	int	fd;

	game->height = count_line(game);
	if (game->height == -1)
		return (1);
	game->map = ft_calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		return (err_parser(2), 1);
	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		return (err_parser(3), 1);
	if (get_map(game, fd, 0))
		return (1);
	return (0);
}
