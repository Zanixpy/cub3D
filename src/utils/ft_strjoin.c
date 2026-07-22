/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:36:02 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 07:53:00 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	n;
	char			*tmp;
	size_t			fsize;
	size_t			ssize;

	fsize = ft_strlen(s1);
	ssize = ft_strlen(s2);
	tmp = malloc((fsize + ssize + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	n = 0;
	while (*s1)
	{
		tmp[n] = *s1;
		s1++;
		n++;
	}
	while (*s2)
	{
		tmp[n] = *s2;
		s2++;
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}
