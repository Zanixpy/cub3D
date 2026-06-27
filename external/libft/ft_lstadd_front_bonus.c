/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:44:44 by omawele           #+#    #+#             */
/*   Updated: 2025/11/11 12:42:01 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*p;

	p = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	*lst = new;
	new->next = p;
}
