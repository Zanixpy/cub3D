/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:14:27 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 10:31:19 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	err_parser(int code)
{
	ft_putendl_fd("Error", 2);
	if (code == 0)
		ft_putendl_fd("args: only take one argument", 2);
	else if (code == 1)
		ft_putendl_fd("file: map -> .cub and textures images -> .xpm extension",
			2);
	else if (code == 2)
		ft_putendl_fd("malloc: failed", 2);
	else if (code == 3)
		perror("file");
	else if (code == 4)
		ft_putendl_fd("map: miss, duplicate or wrong element/info", 2);
	else if (code == 5)
		ft_putendl_fd("map: incorrect RGB, format: X -> [0,255]: XXX,XXX,XXX",
			2);
	else if (code == 6)
		ft_putendl_fd("map: content is incorrect", 2);
	else if (code == 7)
		ft_putendl_fd("map: not closed/surrounded by walls", 2);
	else if (code == 8)
		ft_putendl_fd("map: No player or duplicate player", 2);
	else if (code == 9)
		ft_putendl_fd("map: duplicate textures/color", 2);
}

void	err_mlx(int code)
{
	ft_putendl_fd("Error", 2);
	if (code == 0)
		ft_putendl_fd("mlx: init failed", 2);
	else if (code == 1)
		ft_putendl_fd("mlx: malloc failed for image", 2);
	else if (code == 2)
		ft_putendl_fd("mlx: malloc failed for image address", 2);
}
