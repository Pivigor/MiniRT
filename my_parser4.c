/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_parser4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarlic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:59 by jgarlic           #+#    #+#             */
/*   Updated: 2022/02/16 10:26:59 by jgarlic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_parser.h"

void	my_parse_cylinder2(char **line_split, t_parse *parse,
		t_cylinder *cylinder)
{
	char		**split;

	split = ft_split(line_split[5], ',');
	cylinder->rgb.x = ft_atoi(split[0]);
	cylinder->rgb.y = ft_atoi(split[1]);
	cylinder->rgb.z = ft_atoi(split[2]);
	my_free_split(split);
	parse->type = Cylinder;
	parse->object = cylinder;
}

void	my_parse_cylinder(char **line_split, t_parse *parse)
{
	t_cylinder	*cylinder;
	char		**split;

	if (my_split_size(line_split) < 6 || my_count_chars(line_split[1], ',') < 2
		|| my_count_chars(line_split[2], ',') < 2
		|| my_count_chars(line_split[5], ',') < 2)
		return ;
	cylinder = malloc(sizeof(t_cylinder));
	split = ft_split(line_split[1], ',');
	cylinder->coord.x = my_atod(split[0]);
	cylinder->coord.y = my_atod(split[1]);
	cylinder->coord.z = my_atod(split[2]);
	my_free_split(split);
	split = ft_split(line_split[2], ',');
	cylinder->orient.x = my_atod(split[0]);
	cylinder->orient.y = my_atod(split[1]);
	cylinder->orient.z = my_atod(split[2]);
	my_free_split(split);
	cylinder->diameter = my_atod(line_split[3]);
	cylinder->height = my_atod(line_split[4]);
	my_parse_cylinder2(line_split, parse, cylinder);
}

double	my_atod(char *str)
{
	char	**split;
	double	ret;
	double	temp;
	int		division;
	int		modulo;

	division = 0;
	modulo = 0;
	split = ft_split(str, '.');
	if (my_split_size(split) >= 1)
		division = ft_atoi(split[0]);
	if (my_split_size(split) >= 2)
		modulo = ft_atoi(split[1]);
	my_free_split(split);
	ret = modulo;
	modf(ret, &temp);
	while (temp != 0)
	{
		ret /= 10;
		modf(ret, &temp);
	}
	ret += division;
	return (ret);
}

int	my_count_chars(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
