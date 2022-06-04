/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:33:56 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:33:57 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_parser.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2)
	{
		printf("Bad args\n");
		return (0);
	}
	list = my_minirt_parse(argv[1]);
	if (list != NULL)
	{
		my_full_print(list);
		printf("Parsing OK\n");
	}
	else
		printf("Parsing ERROR\n");
}
