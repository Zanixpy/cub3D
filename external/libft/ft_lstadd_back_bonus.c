/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:42:54 by omawele           #+#    #+#             */
/*   Updated: 2025/11/07 15:28:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			p->next = new;
			return ;
		}
		p = p->next;
	}
}
