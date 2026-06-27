/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 20:14:27 by omawele           #+#    #+#             */
/*   Updated: 2026/06/27 22:01:01 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void exit_err_parser(int code)
{
    ft_putendl_fd("Error", 2);
    if (code == 0)
        ft_putendl_fd("No argument", 2);
    else if (code == 1)
        ft_putendl_fd("Too much argument", 2);
    else if (code == 2)
        ft_putendl_fd("Filename is incorrect", 2);
    else if (code == 3)
        ft_putendl_fd("Malloc failed", 2);
    else if (code == 4);
        strerror(errno);
    exit (1);
}
