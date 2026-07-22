/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:18 by omawele           #+#    #+#             */
/*   Updated: 2026/07/22 07:51:43 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb * size > SIZE_MAX || nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
