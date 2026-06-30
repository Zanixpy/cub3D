/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:44:16 by omawele           #+#    #+#             */
/*   Updated: 2026/06/30 18:32:03 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (parser(ac, av, &game))
	{
		printf("WRONG PARSING\n");
		struct_destroy(&game);
		return (1);
	}
	printf("VALID PARSING\n");
	return (0);
}
