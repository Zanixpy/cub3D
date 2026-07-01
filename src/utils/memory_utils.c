/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 21:21:19 by omawele           #+#    #+#             */
/*   Updated: 2026/07/01 14:43:27 by omawele          ###   ########.fr       */
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

void	close_fd(int *fd)
{
	if (*fd > -1)
		close(*fd);
	*fd = -2;
}


char **ft_arrdup(char **tab)
{
	char **tmp;
	int len;
	int i;

	len = array_size(tab);
	tmp = ft_calloc(len + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		if (!tmp[i])
			return (free_char_array_n(&tmp, i), NULL);
		i++;
	}
	return (tmp);
}