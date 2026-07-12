/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:10:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/13 01:32:30 by omawele          ###   ########.fr       */
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
	if (load_elements(game))
		return (1);
	if (load_map(game))
		return (1);
	return (0);
}

int	is_valid_config(t_game *game)
{
	char	**map;

	if (check_player(game) || !game->player_direction)
		return (err_parser(9), 1);
	map = ft_arrdup(game->map);
	if (!map)
		return (err_parser(3), 1);
	flood_algorithm(&map, game->pos_x, game->pos_y);
	if (check_wall(game, map))
		return (free_char_array(&map), err_parser(8), 1);
	free_char_array(&map);
	return (0);
}

int	parser(char **av, t_game **game)
{
	*game = struct_init();
	if (!(*game))
		return (err_parser(3), 1);
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
