/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:30:31 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 07:52:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strchr(const char *s, int c)
{
	char	src;

	src = c;
	while (*s)
	{
		if (*s == src)
			return ((char *)s);
		s++;
	}
	if (*s == src)
		return ((char *)s);
	return (NULL);
}
