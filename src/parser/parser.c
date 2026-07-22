/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:10:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:46:02 by omawele          ###   ########.fr       */
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

int	load_textures(t_texture *tex)
{
	tex->no_texture.addr = mlx_get_data_addr(tex->no_texture.img,
			&tex->no_texture.bits_per_pixel, &tex->no_texture.line_length,
			&tex->no_texture.endian);
	if (!tex->no_texture.addr)
		return (1);
	tex->so_texture.addr = mlx_get_data_addr(tex->so_texture.img,
			&tex->so_texture.bits_per_pixel, &tex->so_texture.line_length,
			&tex->so_texture.endian);
	if (!tex->so_texture.addr)
		return (1);
	tex->we_texture.addr = mlx_get_data_addr(tex->we_texture.img,
			&tex->we_texture.bits_per_pixel, &tex->we_texture.line_length,
			&tex->we_texture.endian);
	if (!tex->we_texture.addr)
		return (1);
	tex->ea_texture.addr = mlx_get_data_addr(tex->ea_texture.img,
			&tex->ea_texture.bits_per_pixel, &tex->ea_texture.line_length,
			&tex->ea_texture.endian);
	if (!tex->ea_texture.addr)
		return (1);
	return (0);
}

int	parse_map_file(t_game *game)
{
	int	fd;

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		return (err_parser(3), -1);
	if (load_elements(game, fd))
		return (1);
	if (load_textures(&game->tex))
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
	game->pos_x += 0.5;
	game->pos_y += 0.5;
	game->dir_y = 0.0;
	game->dir_x = 0.0;
	if (game->player_direction == 'N')
		game->dir_y = 1.0;
	else if (game->player_direction == 'S')
		game->dir_y = -1.0;
	else if (game->player_direction == 'E')
		game->dir_x = 1.0;
	else if (game->player_direction == 'W')
		game->dir_x = -1.0;
	game->plane_x = -game->dir_y * 0.66;
	game->plane_y = game->dir_x * 0.66;
	return (free_char_array(&map), 0);
}

int	parser(char **av, t_game **game)
{
	*game = struct_init();
	if (!(*game))
		return (err_parser(2), 1);
	if (init_mlx(*game))
		return (1);
	if (set_filename(*game, av[1]))
		return (1);
	if (parse_map_file(*game))
		return (1);
	if (is_valid_config(*game))
		return (1);
	return (0);
}
