/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:44:16 by omawele           #+#    #+#             */
/*   Updated: 2026/07/16 13:52:50 by omawele          ###   ########.fr       */
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

    // --- Joueur et Vecteurs Raycasting ---
    printf("Player Dir   : %c\n", game->player_direction);
    printf("Position     : X = %f, Y = %f\n", game->pos_x, game->pos_y);
    printf("Direction Vec: X = %f, Y = %f\n", game->dir_x, game->dir_y);
    printf("Camera Plane : X = %f, Y = %f\n", game->plane_x, game->plane_y);

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
    mlx_loop_hook(game->mlx, render_graphics, game);
    mlx_loop(game->mlx);
	struct_destroy(&game);
	return (0);
}
