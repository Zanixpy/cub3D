/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 21:21:19 by omawele           #+#    #+#             */
/*   Updated: 2026/06/27 21:22:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_char_array_n(char ***tab, int n)
{
	if (!(*tab))
		return ;
	while (n >= 0)
	{
		free((*tab)[n]);
		n--;
	}
	free(*tab);
    *tab = NULL;
}

void	free_char_array(char ***tab)
{
	int	n;

	if (!(*tab))
		return ;
	n = 0;
	while ((*tab)[n])
	{
		free((*tab)[n]);
		n++;
	}
	free(*tab);
    *tab = NULL;
}

void	free_str(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}
