/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:44:16 by omawele           #+#    #+#             */
/*   Updated: 2026/07/01 14:53:47 by omawele          ###   ########.fr       */
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
    printf("Height    : %d\n", game->height);
    printf("Width     : %d\n", game->width);
    printf("Map       :\n");
    if (game->map)
        print_map(game->map);
    else
    {
        printf("  (NULL)\n");
    }

    // --- Fichier ---
    if (game->filename)
        printf("Filename  : %s\n", game->filename);
    printf("FD        : %d\n", game->fd);

    // --- Joueur ---
    if (game->player_direction)
        printf("Player Dir: %c\n", game->player_direction);
    printf("Pos XY    : X = %d, Y = %d\n", game->pos_xy[0], game->pos_xy[1]);

    // --- Chemins des Textures (Strings) ---
    if (game->NO_texture)
        printf("NO_texture: %s\n", game->NO_texture);
    if (game->SO_texture)
        printf("SO_texture: %s\n", game->SO_texture);
    if (game->WE_texture)
        printf("WE_texture: %s\n", game->WE_texture);
    if (game->EA_texture)
        printf("EA_texture: %s\n", game->EA_texture);

    // --- Couleurs RGB ---
    printf("Floor RGB  : R=%d, G=%d, B=%d\n", 
            game->floor_RGB[0], game->floor_RGB[1], game->floor_RGB[2]);
    printf("Ceiling RGB: R=%d, G=%d, B=%d\n", 
            game->ceiling_RGB[0], game->ceiling_RGB[1], game->ceiling_RGB[2]);

    printf("======================\n");
}


int	main(int ac, char **av)
{
	t_game	*game;

	if (parser(ac, av, &game))
	{
		printf("WRONG PARSING\n");
		struct_destroy(&game);
		return (1);
	}
    print_struct(game);
	printf("VALID PARSING\n");
	return (0);
}
