/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:20:15 by jgarlic           #+#    #+#             */
/*   Updated: 2021/12/02 23:20:16 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_global_libs.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (lst != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			begin = *lst;
			while (begin->next != 0)
				begin = begin->next;
			begin->next = new;
		}
	}
}
