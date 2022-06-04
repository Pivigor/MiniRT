/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 23:20:56 by jgarlic           #+#    #+#             */
/*   Updated: 2021/12/02 23:20:58 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_global_libs.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*begin;
	int		size;

	begin = lst;
	size = 0;
	while (begin != 0)
	{
		begin = begin->next;
		size++;
	}
	return (size);
}
