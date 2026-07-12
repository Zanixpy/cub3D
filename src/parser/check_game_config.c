/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_config.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 00:52:46 by omawele           #+#    #+#             */
/*   Updated: 2026/07/13 01:15:56 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_wall_border(t_game *game, char **map, int *x, int y)
{
	if (*x == 0)
	{
		while (map[y][*x] && map[y][*x] == SPACE)
			(*x)++;
		if (map[y][*x] != '1')
			return (1);
	}
	if (map[y][*x + 1] == '\0' && map[y][*x] != '1')
		return (1);
	if ((y == 0 || y == game->height - 1) && (map[y][*x] != '1'
			&& map[y][*x] != SPACE))
		return (1);
	if (map[y][*x] == 'T' && ((map[y][*x + 1] != '1' && map[y][*x + 1] != 'T')
			|| (map[y][*x - 1] != '1' && map[y][*x - 1] != 'T') || (map[y
				+ 1][*x] != '1' && map[y + 1][*x] != 'T') || (map[y
				- 1][*x] != '1' && map[y - 1][*x] != 'T')))
		return (1);
	return (0);
}

int	check_player(t_game *game)
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
					game->pos_x = x;
					game->pos_y = y;
				}
				else
					return (1);
			}
			x++;
		}
	}
	return (0);
}

void	flood_algorithm(char ***map, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (!(*map)[y][x] || (*map)[y][x] == SPACE || (*map)[y][x] == '1'
		|| (*map)[y][x] == 'T')
		return ;
	(*map)[y][x] = 'T';
	flood_algorithm(map, x, y + 1);
	flood_algorithm(map, x, y - 1);
	flood_algorithm(map, x + 1, y);
	flood_algorithm(map, x - 1, y);
}

int	check_wall(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_wall_border(game, map, &x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
