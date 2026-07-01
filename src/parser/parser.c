/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:10:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/01 15:32:30 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	check_nb_args(int ac)
{
	if (ac != 2)
	{
		if (ac < 2)
			exit_err_parser(0);
		else
			exit_err_parser(1);
	}
}

static int	get_fd_and_filename(t_game *game, char *av)
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

static int	check_player(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				if (!game->player_direction)
				{
					game->player_direction = game->map[y][x];
					game->pos_xy[0] = x;
					game->pos_xy[1] = y;
				}
				else
					return (1);
			}
			x++;
		}
	}
	return (0);
}

static void	flood_algorithm(char ***map, int x, int y)
{
	if (!(*map)[y][x] || (*map)[y][x] == SPACE || (*map)[y][x] == '1'
		|| (*map)[y][x] == 'T')
		return ;
	(*map)[y][x] = 'T';
	flood_algorithm(map, x, y + 1);
	flood_algorithm(map, x, y - 1);
	flood_algorithm(map, x + 1, y);
	flood_algorithm(map, x - 1, y);
}

static int	check_wall_border(t_game *game, char **map, int x, int y)
{
	if (x == 0)
	{
		while (map[y][x] && map[y][x] == SPACE)
			x++;
		if (map[y][x] != '1')
			return (1);
	}
	if (map[y][x + 1] == '\0')
	{
		if (map[y][x] != '1')
			return (1);
	}
	if ((y == 0 || y == game->height - 1))
	{
		if (map[y][x] != '1' && map[y][x] != SPACE)
			return (1);
	}
	if (map[y][x] == 'T')
	{
		if (map[y][x + 1] != '1' && map[y][x + 1] != 'T' && map[y][x - 1] != '1'
			&& map[y][x - 1] != 'T' && map[y + 1][x] != '1' && map[y
			+ 1][x] != 'T' && map[y - 1][x] != '1' && map[y - 1][x] != 'T')
			return (1);
	}
    return (0);
}

static int	check_wall(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
            if (check_wall_border(game, map, x, y))
                return (1);
            x++;
		}
        y++;
	}
	return (0);
}



int	parser(int ac, char **av, t_game **game)
{
	char	**map;

	check_nb_args(ac);
	*game = struct_init();
	if (!(*game))
		exit_parser_free_struct(game, 3);
	if (get_fd_and_filename(*game, av[1]))
		return (1);
	if (fill_data(*game))
		return (1);
	if (fill_map(*game))
		return (1);
	if (check_player(*game))
		return (err_parser(9), 1);
	map = ft_arrdup((*game)->map);
	if (!map)
		return (err_parser(3), 1);
	flood_algorithm(&map, (*game)->pos_xy[0], (*game)->pos_xy[1]);
	if (check_wall(*game, map))
		return (free_char_array(&map), err_parser(8), 1);
	free_char_array(&map);
	return (0);
}
