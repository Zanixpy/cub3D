/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 21:14:56 by omawele           #+#    #+#             */
/*   Updated: 2026/07/20 07:55:10 by omawele          ###   ########.fr       */
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

char	*clean_str(char *s, int mode)
{
	char	*tmp;
	char	*str;
	int		len;
	int		i;

	if (mode == 0)
		tmp = ft_strtrim(s, " ");
	else
		tmp = ft_strdup(s);
	if (!tmp)
		return (NULL);
	len = ft_strlen(tmp) - 1;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (free(tmp), NULL);
	i = 0;
	while (i < len)
	{
		str[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (str);
}


int	is_space(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != SPACE && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
