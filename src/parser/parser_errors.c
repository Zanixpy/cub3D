/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:14:27 by omawele           #+#    #+#             */
/*   Updated: 2026/07/01 10:53:11 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	err_parser(int code)
{
	ft_putendl_fd("Error", 2);
	if (code == 0)
		ft_putendl_fd("args: no argument", 2);
	else if (code == 1)
		ft_putendl_fd("args: too much argument", 2);
	else if (code == 2)
		ft_putendl_fd("file: only take named file with .cub extension", 2);
	else if (code == 3)
		ft_putendl_fd("malloc: failed", 2);
	else if (code == 4)
		perror("file");
	else if (code == 5)
		ft_putendl_fd("map: miss, duplicate or wrong element/info", 2);
	else if (code == 6)
		ft_putendl_fd("map: incorrect RGB, format: X -> [0,255]: XXX,XXX,XXX",
			2);
	else if (code == 7)
		ft_putendl_fd("map: content is incorrect", 2);
    else if (code == 8)
		ft_putendl_fd("map: not closed/surrounded by walls", 2);
    else if (code == 9)
		ft_putendl_fd("map: duplicate player", 2);
            
}

void	exit_err_parser(int code)
{
	err_parser(code);
	exit(1);
}

void	exit_parser_free_struct(t_game **game, int code)
{
	struct_destroy(game);
	err_parser(code);
	exit(1);
}
