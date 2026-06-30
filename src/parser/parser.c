/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:10:41 by omawele           #+#    #+#             */
/*   Updated: 2026/06/30 19:50:05 by omawele          ###   ########.fr       */
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
		return (err_parser(3), 1);
	len = ft_strlen(game->filename);
	if (len < 5)
		return (err_parser(2), 1);
	if (ft_strcmp(game->filename + (len - 4), ".cub"))
		return (err_parser(2), 1);
	game->fd = open(game->filename, O_RDONLY);
	if (game->fd == -1)
		return (err_parser(4), 1);
	return (0);
}

static int check_player(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == PLAYER_DIR)
            {
                if (!game->player_direction)
                {
                    game->player_direction = game->map[y][x];
                    game->pos_xy[0] = x;
                    game->pos_xy[1] = y;                    
                }
                else
                    return (0);
                x++;
            }
        }
        y++;        
    }
    return (1);
}

static int check_wall(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x] && (y == 0 || y == game->height - 1))
        {
            if (x == 0 || game->map[y][x + 1] == '\0')
            {
                if (game->map[y][x] != '1')
                    return (0);
            } 
            else if (game->map[y][x] != '1' && game->map[y][x] != SPACE)
                return (0);
        }         
        while (game->map[y][x] && (y != 0 || y != game->height - 1))
        {
            if (x == 0 || game->map[y][x + 1] == '\0')
            {
                if (game->map[y][x] != '1')
                    return (0);
            } 
            x++;
        }
        y++;        
    }
    return (1);
}

int	parser(int ac, char **av, t_game **game)
{
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
	return (0);
}
