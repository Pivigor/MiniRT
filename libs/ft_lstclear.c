/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:20:23 by jgarlic           #+#    #+#             */
/*   Updated: 2021/12/02 23:20:24 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "my_global_libs.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*next;

	if (lst != 0)
	{
		begin = *lst;
		while (begin != 0)
		{
			next = begin->next;
			(*del)(begin->content);
			free(begin);
			begin = next;
		}
		*lst = 0;
	}
}
