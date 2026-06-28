/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:10:41 by omawele           #+#    #+#             */
/*   Updated: 2026/06/28 17:46:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void check_nb_args(int ac)
{
    if (ac != 2)
    {
        if (ac < 2)
            exit_err_parser(0);
        else
            exit_err_parser(1);
    }
}

static int check_file(char *filename)
{
    char **tab;
    int len;
    int fd;
    
    len = ft_strlen(filename);
    if (filename < 4)
        exit_err_parser(2);
    if (ft_strchr(filename, '/'))
    {
        tab = ft_split(filename, '/');
        if (!tab)
            exit_err_parser(3);
        filename = tab[array_size(tab) - 1];   
    }
    if (ft_strcmp(filename + (len - 5), ".cub"))
    {
        free_char_array(&tab);
        exit_err_parser(2);
    }
    fd = open(filename, O_RDONLY);
    free_char_array(&tab);
    if (fd == -1)
        exit_err_parser(4);
    return (fd);
}

static int initialize_data_in_struct(t_game *game)
{
    
    
    return (0);
}


int parser(int ac, char **av, t_game **game)
{
    int fd;
    
    check_nb_args(ac);
    fd = check_file(av[1]);
    *game = struct_init();
    if (!*game)
    {
        close(fd);
        exit_err_parser(3);
    }
    (*game)->fd = fd;
    if (initialize_data_in_struct(*game))
    {
        struct_destroy(game);
        exit_err_parser(3);
    }    
    return (0);
}
