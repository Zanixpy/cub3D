/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 21:14:56 by omawele           #+#    #+#             */
/*   Updated: 2026/06/27 21:30:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	n;

	n = 0;
	while (s1[n] || s2[n])
	{
		if (s1[n] != s2[n])
			return (1);
		n++;
	}
	return (0);
}

int	array_size(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}