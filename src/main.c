/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:44:16 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:32:51 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	exit_cleanup(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	struct_destroy(&game);
	exit(0);
}

static void	check_delta(t_game *game)
{
	if (game->delta_time > 0.033)
		game->delta_time = 0.033;
	if (game->delta_time < 0.008)
		game->delta_time = 0.008;
}

int	game_loop(void *param)
{
	t_game	*game;
	double	current_time;
	double	frame_time;

	game = (t_game *)param;
	current_time = get_time();
	frame_time = current_time - game->last_frame;
	if (frame_time < game->frame_time_ms * 0.9)
		return (0);
	game->delta_time = frame_time / 1000.0;
	check_delta(game);
	game->last_frame = current_time;
	if (game->p.foward)
		go_foward(game);
	if (game->p.backward)
		go_backward(game);
	if (game->p.left)
		go_left(game);
	if (game->p.right)
		go_right(game);
	if (game->p.rotate_right)
		rotate_right(game);
	if (game->p.rotate_left)
		rotate_left(game);
	return (render_graphics(param), 0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (err_parser(0), 1);
	if (parser(av, &game))
	{
		struct_destroy(&game);
		return (1);
	}
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_hold, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->mlx_win, 17, 0, &exit_cleanup, game);
	mlx_loop_hook(game->mlx, &game_loop, game);
	mlx_loop(game->mlx);
	return (struct_destroy(&game), 0);
}
