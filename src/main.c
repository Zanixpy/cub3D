/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:44:16 by omawele           #+#    #+#             */
/*   Updated: 2026/07/07 17:02:23 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("  [%d] %s\n", i, map[i]);
        i++;
    }
}

void print_struct(t_game *game)
{
    if (!game)
    {
        printf("Erreur : La structure game est NULL.\n");
        return;
    }

    printf("=== STRUCTURE GAME ===\n");

    // --- Cartographie et Dimensions ---
    printf("Height       : %d\n", game->height);
    printf("Width        : %d\n", game->width);
    printf("Map          :\n");
    if (game->map)
    {
        for (int i = 0; game->map[i] != NULL; i++)
            printf("  [%d] %s\n", i, game->map[i]);
    }
    else
    {
        printf("  (NULL)\n");
    }

    // --- Fichier ---
    printf("Filename     : %s\n", game->filename ? game->filename : "(NULL)");
    printf("FD           : %d\n", game->fd);

    // --- Joueur et Vecteurs Raycasting ---
    printf("Player Dir   : %c\n", game->player_direction);
    printf("Position     : X = %f, Y = %f\n", game->posX, game->posY);
    printf("Direction Vec: X = %f, Y = %f\n", game->dirX, game->dirY);
    printf("Camera Plane : X = %f, Y = %f\n", game->planX, game->planY);

    // --- Chemins des Textures (Strings) ---
    printf("NO_texture   : %s\n", game->NO_texture ? game->NO_texture : "(NULL)");
    printf("SO_texture   : %s\n", game->SO_texture ? game->SO_texture : "(NULL)");
    printf("WE_texture   : %s\n", game->WE_texture ? game->WE_texture : "(NULL)");
    printf("EA_texture   : %s\n", game->EA_texture ? game->EA_texture : "(NULL)");

    // --- Couleurs RGB ---
    printf("Floor RGB    : R=%d, G=%d, B=%d\n", 
            game->floor_RGB[0], game->floor_RGB[1], game->floor_RGB[2]);
    printf("Ceiling RGB  : R=%d, G=%d, B=%d\n", 
            game->ceiling_RGB[0], game->ceiling_RGB[1], game->ceiling_RGB[2]);

    printf("======================\n");
}

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





int	main(int ac, char **av)
{
	t_game	*game;

    check_nb_args(ac);
	if (parser(av, &game))
        exit_parser_free_struct(&game, -1);
    // if (set_floor_ceiling(game))
    //     exit_mlx_free_struct(&game, 2);
    set_2D_grid(game);
    mlx_hook(game->mlx_win, 2, 1L<<0, handleKeyPress, game);
    mlx_hook(game->mlx_win, 3, 1L<<1, handleKeyRelease, game);
    mlx_loop_hook(game->mlx, handleMoves, game);
    mlx_loop(game->mlx);
	struct_destroy(&game);
	return (0);
}
