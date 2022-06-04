/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:20:36 by jgarlic           #+#    #+#             */
/*   Updated: 2021/12/02 23:20:37 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_global_libs.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*begin;

	begin = lst;
	if (begin != 0)
		while (begin->next != 0)
			begin = begin->next;
	return (begin);
}
