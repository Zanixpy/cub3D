/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:36:11 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 08:07:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*d;
	unsigned int	i;

	d = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		d[i] = 0;
		i++;
	}
}
