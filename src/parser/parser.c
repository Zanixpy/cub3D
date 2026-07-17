/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:10:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/16 12:16:26 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	set_filename(t_game *game, char *filename)
{
	if (check_filename(filename, ".cub"))
		return (1);
	game->filename = ft_strdup(filename);
	if (!game->filename)
		return (1);
	return (0);
}

int	parse_map_file(t_game *game)
{
	int fd;

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		return (err_parser(3), -1);
	if (load_elements(game, fd))
		return (1);
	if (load_map(game))
		return (1);
	return (0);
}

int	is_valid_config(t_game *game)
{
	char	**map;

	if (check_player(game) || !game->player_direction)
		return (err_parser(8), 1);
	map = ft_arrdup(game->map);
	if (!map)
		return (err_parser(2), 1);
	flood_algorithm(&map, game->pos_x, game->pos_y, game);
	if (check_wall(game, map))
		return (free_char_array(&map), err_parser(7), 1);
	free_char_array(&map);
	game->plane_x = 0.0;
	game->plane_y = 0.66;
	if (game->player_direction == 'N')
		game->dir_y = 1.0;
	else if (game->player_direction == 'S')
		game->dir_y = -1.0;
	else if (game->player_direction == 'E')
		game->dir_x = 1.0;
	else if (game->player_direction == 'W')
		game->dir_y = -1.0;
	return (0);
}

int	parser(char **av, t_game **game)
{
	*game = struct_init();
	if (!(*game))
		return (err_parser(2), 1);
	if (set_filename(*game, av[1]))
		return (1);
	if (parse_map_file(*game))
		return (1);		
	if (is_valid_config(*game))
		return (1);
	if (init_mlx(*game))
		return (1);
	return (0);
}
